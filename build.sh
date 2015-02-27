#!/bin/sh

# pass V=1 for verbosity

source "$(dirname "${0}")/lib/log.bash"

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

if [ ! -d "$project_build_variant_dir" ]
then
  log 1 "Build directory doesn't exist; rebuilding ..."
  "${project_dir}"/rebuild.sh "$@"
else
  cd "$project_build_variant_dir"
  log 1 "Building ..."
  make -j prefix=$HOME/usr/local/stow/"$project_name" V="$V" check
  build_success=$?
  if [ $build_success -eq 0 ];
  then
    log 1 "build complete"
  else
    log 1 "build failed"
  fi
fi
