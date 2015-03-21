#include "position.hh"
#include "rectangle.hh"

namespace snk {
position::position(int x, int y) : x{x}, y{y} {}

bool operator==(position const& lhs, position const& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(position const& lhs, position const& rhs) {
  return !(lhs == rhs);
}

bool outside(position const& p, rectangle const& b) {
  return p.x < b.p.x || p.x > b.w || p.y < b.p.y || p.y > b.h;
}
}
