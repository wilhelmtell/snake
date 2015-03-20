#include "snake_segment_control.hh"
#include <utility>
#include "rectangle.hh"

namespace snk {
snake_segment_control::snake_segment_control(rectangle rect)
: rect{std::move(rect)} {}
}
