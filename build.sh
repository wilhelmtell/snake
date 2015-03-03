#!/bin/sh

# V=1 for verbosity
# Q=1 for quiet build

source "$(dirname "${0}")/lib/log.bash"

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

if [ ! -d "$project_build_variant_dir" ]
then
  info "Build directory doesn't exist; rebuilding ..."
  "${project_dir}"/rebuild.sh "$@"
else
  cd "$project_build_variant_dir"
  info "Building ..."
  if [ ${Q} -eq 0 -a ${V} -ge 3 ];
  then
    make --trace --debug -k -j prefix=$HOME/usr/local/stow/"$project_name" V=$((V-1)) check
  elif [ ${Q} -eq 0 -a ${V} -ge 2 ];
  then
    make --debug -k -j prefix=$HOME/usr/local/stow/"$project_name" V=$((V-1)) check
  elif [ ${Q} -eq 0 -a ${V} -ge 1 ];
  then
    make -k -j prefix=$HOME/usr/local/stow/"$project_name" V=$((V-1)) check
  elif [ ${Q} -eq 0 -a ${V} -ge 0 ];
  then
    V= make -k -j prefix=$HOME/usr/local/stow/"$project_name" check
  else
    V= make --silent -k -j prefix=$HOME/usr/local/stow/"$project_name" check
  fi
  build_success=$?
  if [ $build_success -eq 0 ];
  then
    info "build complete"
  else
    info "build failed"
  fi
fi
