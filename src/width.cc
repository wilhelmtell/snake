#include "width.hh"

namespace snk {
width::width(width::value_type value) : value{value} {}

width::operator value_type() const { return value; }
}
