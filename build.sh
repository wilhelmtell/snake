#!/bin/sh

project_dir="$(dirname "$0")"
project_name="$(basename "$project_dir")"
build_variant="debug"
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
project_build_variant_dir="$project_build_dir/$build_variant";

echo "project_dir=\"$project_dir\"";
echo "project_name=\"$project_name\"";
echo "build_variant=\"$build_variant\"";
echo "project_build_dir=\"$project_build_dir\"";
echo "project_build_variant_dir=\"$project_build_variant_dir\"";

if [ ! -d "$project_build_variant_dir" ]
then
  echo "NOTE: Build directory doesn't exist. Rebuilding."
  "${project_dir}"/rebuild.sh "$@"
else
  cd "$project_build_variant_dir" &&
    make -j prefix=$HOME/usr/local/stow/"$project_name" V=1 check
  build_success=$?
  if [ $build_success -eq 0 ];
  then
    echo "build complete"
    [ "$(uname -s)" = Darwin ] && say --voice=Vicki "build complete"
  else
    echo "build failed"
    [ "$(uname -s)" = Darwin ] && say --voice=Vicki "build failed"
  fi
fi
