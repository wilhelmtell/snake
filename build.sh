#!/bin/sh

# pass V=1 for verbosity
V=${V:-0}

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

if [ ! -d "$project_build_variant_dir" ]
then
  [ "$V" -ge 1 ] && echo "Build directory doesn't exist; rebuilding ..."
  "${project_dir}"/rebuild.sh "$@"
else
  cd "$project_build_variant_dir"
  [ "$V" -ge 1 ] && echo "Building ..."
  make -j prefix=$HOME/usr/local/stow/"$project_name" V="$V" check
  build_success=$?
  if [ $build_success -eq 0 ];
  then
    echo "build complete"
  else
    echo "build failed"
  fi
fi
