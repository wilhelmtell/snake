#include "position_to_string.hh"
#include "../src/position.hh"
#include <iostream>

namespace snk {
std::ostream& operator<<(std::ostream& out, position const& pos) {
  return out << '(' << pos.x << ", " << pos.y << ')';
}
}
