#include "point_to_string.hh"
#include "../src/point.hh"
#include <iostream>

namespace snk {
std::ostream& operator<<(std::ostream& out, point const& pos) {
  return out << '(' << pos.x << ", " << pos.y << ')';
}
}
