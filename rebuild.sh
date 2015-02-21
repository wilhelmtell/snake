#!/bin/sh

# pass V=1 for verbosity

error() {
  echo "Error: $1" >&2
  exit 1
}

[ "$V" = 2 ] && echo "Setting project_dir ..."
project_dir="$(dirname "$0")"
[ "$V" = 1 ] && echo "project_dir=\"${project_dir}\""
[ "$V" = 2 ] && echo "Setting project_name ..."
project_name="$(basename "$project_dir")"
[ "$V" = 1 ] && echo "project_name=\"${project_name}\""
[ "$V" = 2 ] && echo "Setting build_variant ..."
build_variant="${build_variant:-debug}"
[ "$V" = 1 ] && echo "build_variant=\"${build_variant}\""
[ "$V" = 2 ] && echo "Setting project_build_dir ..."
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
[ "$V" = 1 ] && echo "project_build_dir=\"${project_build_dir}\""
[ "$V" = 2 ] && echo "Setting project_build_variant_dir ..."
project_build_variant_dir="$project_build_dir/$build_variant";
[ "$V" = 1 ] && echo "project_build_variant_dir=\"${project_build_variant_dir}\""

[ "$V" = 1 ] && echo "Autoreconfing ..."
autoreconf --install --force --warnings=all "$project_dir" ||
  error "autoreconf failed."
[ "$V" = 1 ] && echo "Wiping build ..."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
[ "$V" = 2 ] && echo "Creating build directory ..."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
[ "$V" = 1 ] && echo "Configuring build ..."
cd "$project_build_variant_dir" &&
  CONFIG_SITE=~/config.site."$build_variant".clang "$project_dir"/configure --prefix=$HOME/usr/local ||
  error "Build configuration failed."
"${project_dir}"/build.sh "$@"
