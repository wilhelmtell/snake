#!/bin/sh

# pass V=1 for verbosity
V=${V:-0}

error() {
  echo "Error: $1" >&2
  exit 1
}

[ "$V" -ge 2 ] && echo "Setting project_dir ..."
project_dir="$(dirname "$0")"
[ "$V" -ge 1 ] && echo "project_dir=\"${project_dir}\""
[ "$V" -ge 2 ] && echo "Setting project_name ..."
project_name="$(basename "$project_dir")"
[ "$V" -ge 1 ] && echo "project_name=\"${project_name}\""
[ "$V" -ge 2 ] && echo "Setting build_variant ..."
build_variant="${build_variant:-debug}"
[ "$V" -ge 1 ] && echo "build_variant=\"${build_variant}\""
[ "$V" -ge 2 ] && echo "Setting project_build_dir ..."
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
[ "$V" -ge 1 ] && echo "project_build_dir=\"${project_build_dir}\""
[ "$V" -ge 2 ] && echo "Setting project_build_variant_dir ..."
project_build_variant_dir="$project_build_dir/$build_variant";
[ "$V" -ge 1 ] && echo "project_build_variant_dir=\"${project_build_variant_dir}\""
[ "$V" -ge 2 ] && echo "Setting CONFIG_SITE ..."
CONFIG_SITE="$HOME/config.site.${build_variant}.clang"
[ "$V" -ge 1 ] && echo "CONFIG_SITE=\"${CONFIG_SITE}\""

if [[ -d "$CONFIG_SITE" || ! -r "$CONFIG_SITE" ]];
then
  error "CONFIG_SITE file unreadable or not found."
fi

[ "$V" -ge 1 ] && echo "Autoreconfing ..."
autoreconf --install --force --warnings=all "$project_dir" ||
  error "autoreconf failed."
[ "$V" -ge 1 ] && echo "Wiping build ..."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
[ "$V" -ge 2 ] && echo "Creating build directory ..."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
[ "$V" -ge 1 ] && echo "Configuring build ..."
cd "$project_build_variant_dir" &&
  CONFIG_SITE="${CONFIG_SITE}" "$project_dir"/configure --prefix=$HOME/usr/local ||
  error "Build configuration failed."
"${project_dir}"/build.sh "$@"
