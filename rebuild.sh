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

autoreconf --install --force --warnings=all "$project_dir" &&
  rm -rf "$project_build_variant_dir" &&
  mkdir -p "$project_build_variant_dir" &&
  cd "$project_build_variant_dir" &&
  CONFIG_SITE=~/config.site."$build_variant".clang "$project_dir"/configure --prefix=$HOME/usr/local &&
  make -j prefix=$HOME/usr/local/stow/"$project_name" V=1 check

if [ $? -eq 0 ];
then
  say --voice=Vicki "build complete"
else
  say --voice=Vicki "build failed"
fi
