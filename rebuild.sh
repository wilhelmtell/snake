#!/bin/sh

error() {
  echo "Error: $1" >&2
  exit 1
}

project_dir="$(dirname "$0")"
project_name="$(basename "$project_dir")"
build_variant="debug"
project_build_dir="$(realpath "${1:-"${project_dir}/../build_${project_name}"}")"
project_build_variant_dir="$project_build_dir/$build_variant";

autoreconf --install --force --warnings=all "$project_dir" ||
  error "autoreconf failed."
rm -rf "$project_build_variant_dir" ||
  error "wiping build failed."
mkdir -p "$project_build_variant_dir" ||
    error "build directory creation failed."
cd "$project_build_variant_dir" &&
  CONFIG_SITE=~/config.site."$build_variant".clang "$project_dir"/configure --prefix=$HOME/usr/local ||
  error "Build configuration failed."
"${project_dir}"/build.sh "$@"
