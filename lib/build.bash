V=${V:-0}

log() {
  local LEVEL="$1"
  local MSG="$2"
  [ "$V" -ge "${LEVEL}" ] && echo "${MSG}"
}

error() {
  echo "Error: $1" >&2
  exit 1
}
