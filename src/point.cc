#include "point.hh"
#include "rectangle.hh"

namespace snk {
point::point(int x, int y) : x{x}, y{y} {}

bool operator==(point const& lhs, point const& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(point const& lhs, point const& rhs) { return !(lhs == rhs); }

bool outside(point const& p, rectangle const& b) {
  return p.x < b.p.x || p.x > b.w || p.y < b.p.y || p.y > b.h;
}

bool inside(point const& p, rectangle const& b) { return !outside(p, b); }
}
