#include "width.hh"

namespace snk {
width::width(int value) : value{value} {}

int width::get() const { return value; }
}
