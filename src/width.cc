#include "width.hh"

namespace snk {
width::width(width::value_type value) : value{value} {}

width::value_type width::get() const { return value; }
}
