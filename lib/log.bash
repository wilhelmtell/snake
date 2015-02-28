V=${V:-0}

trace() {
  [ "$V" -ge "3" ] && echo "${1}"
}

debug() {
  [ "$V" -ge "2" ] && echo "${1}"
}

info() {
  [ "$V" -ge "1" ] && echo "${1}"
}
