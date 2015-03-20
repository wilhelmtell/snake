#include "snake_segment.hh"
#include <utility>
#include "rectangle.hh"

namespace snk {
snake_segment::snake_segment(rectangle rect)
: rect{std::move(rect)} {}
}
