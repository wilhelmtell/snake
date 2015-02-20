#!/bin/sh

project_dir="$(dirname "$0")"
project_name="$(basename "$project_dir")"
build_variant="debug"
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
project_build_variant_dir="$project_build_dir/$build_variant";

autoreconf --install --force --warnings=all "$project_dir" &&
  rm -rf "$project_build_variant_dir" &&
  mkdir -p "$project_build_variant_dir" &&
  cd "$project_build_variant_dir" &&
  CONFIG_SITE=~/config.site."$build_variant".clang "$project_dir"/configure --prefix=$HOME/usr/local &&
  "${project_dir}"/build.sh "$@"
