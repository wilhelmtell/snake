#include "position.hh"

namespace snk {
position::position(int x, int y) : x{x}, y{y} {}

bool operator==(position const& lhs, position const& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(position const& lhs, position const& rhs) {
  return !(lhs == rhs);
}
}
