#!/bin/sh

# V=1 for verbosity
# Q=1 for quiet build

source "$(dirname "${0}")/lib/log.bash"
source "$(dirname "${0}")/lib/error.bash"

# any of the following variables might contain whitespace (because they
# originate from the user)
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
if [ ${Q} -eq 0 -a ${V} -ge 2 ];
then
  autoreconf --verbose --install --force --warnings=all "$project_dir" ||
    error "autoreconf failed."
elif [ ${V} -ge 0 ];
then
  autoreconf --install --force --warnings=all "$project_dir" ||
    error "autoreconf failed."
fi
info "Wiping build ..."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
debug "Creating build directory ..."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
info "Configuring build ..."
cd "$project_build_variant_dir" &&
  if [ ${Q} -eq 0 ];
  then
    CONFIG_SITE="${CONFIG_SITE}" "$project_dir"/configure --prefix=$HOME/usr/local ||
      error "Build configuration failed."
  else
    CONFIG_SITE="${CONFIG_SITE}" "$project_dir"/configure --silent --prefix=$HOME/usr/local ||
      error "Build configuration failed."
  fi
"${project_dir}"/build.sh "$@"
