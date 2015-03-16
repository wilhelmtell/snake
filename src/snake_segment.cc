#include "snake_segment.hh"
#include <iostream>

namespace snk {
snake_segment::snake_segment(position pos, rectangle rect)
: pos{std::move(pos)}, rect{std::move(rect)} {}
}
