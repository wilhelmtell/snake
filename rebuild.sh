#!/bin/sh

# pass V=1 for verbosity

source "$(dirname "${0}")/lib/log.bash"
source "$(dirname "${0}")/lib/error.bash"

trace "Setting project_dir ..."
project_dir="$(dirname "$0")"
debug "project_dir=\"${project_dir}\""
trace "Setting project_name ..."
project_name="$(basename "$project_dir")"
debug "project_name=\"${project_name}\""
trace "Setting build_variant ..."
build_variant="${build_variant:-debug}"
debug "build_variant=\"${build_variant}\""
trace "Setting project_build_dir ..."
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
debug "project_build_dir=\"${project_build_dir}\""
trace "Setting project_build_variant_dir ..."
project_build_variant_dir="$project_build_dir/$build_variant";
debug "project_build_variant_dir=\"${project_build_variant_dir}\""
trace "Setting CONFIG_SITE ..."
CONFIG_SITE="$HOME/config.site.${build_variant}.clang"
debug "CONFIG_SITE=\"${CONFIG_SITE}\""

if [[ -d "$CONFIG_SITE" || ! -r "$CONFIG_SITE" ]];
then
  error "CONFIG_SITE file unreadable or not found."
fi

info "Autoreconfing ..."
autoreconf --install --force --warnings=all "$project_dir" ||
  error "autoreconf failed."
info "Wiping build ..."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
debug "Creating build directory ..."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
info "Configuring build ..."
cd "$project_build_variant_dir" &&
  CONFIG_SITE="${CONFIG_SITE}" "$project_dir"/configure --prefix=$HOME/usr/local ||
  error "Build configuration failed."
"${project_dir}"/build.sh "$@"
