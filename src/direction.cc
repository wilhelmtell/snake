#include "direction.hh"
#include <utility>

namespace snk {
direction::direction(type_t const& type) : type{std::move(type)} {}

bool operator==(direction const& lhs, direction const& rhs) {
  return lhs.type == rhs.type;
}

bool operator!=(direction const& lhs, direction const& rhs) {
  return !(lhs == rhs);
}
}
