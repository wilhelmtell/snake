#include "direction.hh"

namespace snk {
bool are_opposite(direction const& a, direction const& b) {
  return (a == direction::left && b == direction::right)
         || (a == direction::up && b == direction::down);
}
}
