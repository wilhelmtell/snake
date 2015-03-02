V=${V:-0}
Q=${Q:-0}

trace() {
  [ "$Q" -eq 0 -a "$V" -ge "3" ] && echo "${1}"
}

debug() {
  [ "$Q" -eq 0 -a "$V" -ge "2" ] && echo "${1}"
}

info() {
  [ "$Q" -eq 0 -a "$V" -ge "1" ] && echo "${1}"
}
