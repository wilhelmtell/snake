#include "height.hh"

namespace snk {
height::height(int value) : value{value} {}

int height::get() const { return value; }
}
