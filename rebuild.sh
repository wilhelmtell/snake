#!/bin/sh

# pass V=1 for verbosity

source "$(dirname "${0}")/lib/build.bash"

log 2 "Setting project_dir ..."
project_dir="$(dirname "$0")"
log 1 "project_dir=\"${project_dir}\""
log 2 "Setting project_name ..."
project_name="$(basename "$project_dir")"
log 1 "project_name=\"${project_name}\""
log 2 "Setting build_variant ..."
build_variant="${build_variant:-debug}"
log 1 "build_variant=\"${build_variant}\""
log 2 "Setting project_build_dir ..."
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
log 1 "project_build_dir=\"${project_build_dir}\""
log 2 "Setting project_build_variant_dir ..."
project_build_variant_dir="$project_build_dir/$build_variant";
log 1 "project_build_variant_dir=\"${project_build_variant_dir}\""
log 2 "Setting CONFIG_SITE ..."
CONFIG_SITE="$HOME/config.site.${build_variant}.clang"
log 1 "CONFIG_SITE=\"${CONFIG_SITE}\""

if [[ -d "$CONFIG_SITE" || ! -r "$CONFIG_SITE" ]];
then
  error "CONFIG_SITE file unreadable or not found."
fi

log 1 "Autoreconfing ..."
autoreconf --install --force --warnings=all "$project_dir" ||
  error "autoreconf failed."
log 1 "Wiping build ..."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
log 2 "Creating build directory ..."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
log 1 "Configuring build ..."
cd "$project_build_variant_dir" &&
  CONFIG_SITE="${CONFIG_SITE}" "$project_dir"/configure --prefix=$HOME/usr/local ||
  error "Build configuration failed."
"${project_dir}"/build.sh "$@"
