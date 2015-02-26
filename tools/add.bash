#!/bin/bash

usage() {
  cat <<EOF
usage: $0 [namespace]::<name>

namespace and name must match /[a-zA-Z_][a-zA-Z0-9_]*/

example: $0 gui::draw
EOF
}

validate_qualified_name() {
  test -n "$(echo "$1" |sed '/^\([a-zA-Z_][a-zA-Z0-9_]*\)\?::[a-zA-Z_][a-zA-Z0-9_]*\+$/ ! d')"
}

if [ $# -lt 1 -o ! "($(validate_qualified_name "$1"))" ];
then
  usage
  exit 0
fi

PROJECT_DIR="$(cd $(dirname "$0")/.. && pwd)"
NAMESPACE="$(echo "$1" |awk 'BEGIN { FS="::"; } { print $1; }')"
NAME="$(echo "$1" |awk 'BEGIN { FS="::"; } { print $2; }')"
LOWER_CASE_NAME="$(echo $NAME |tr A-Z a-z)"
UPPER_CASE_NAME="$(echo $NAME |tr a-z A-Z)"
UPPER_CASE_NAMESPACE="$(echo $NAMESPACE |tr a-z A-Z)"

cat <<EOF >"$PROJECT_DIR"/src/${LOWER_CASE_NAME}.hh &&
#ifndef ${UPPER_CASE_NAMESPACE}_${UPPER_CASE_NAME}_HH_
#define ${UPPER_CASE_NAMESPACE}_${UPPER_CASE_NAME}_HH_
#endif
EOF
cat <<EOF >"$PROJECT_DIR"/src/${LOWER_CASE_NAME}.cc &&
#include "${LOWER_CASE_NAME}.hh"
EOF
cat <<EOF >"$PROJECT_DIR"/test/"${LOWER_CASE_NAME}".cc
#include <catch/catch.hpp>
#include "../src/${LOWER_CASE_NAME}.hh"
EOF
