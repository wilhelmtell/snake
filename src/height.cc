#include "height.hh"

namespace snk {
height::height(height::value_type value) : value{value} {}

height::value_type height::get() const { return value; }
}
