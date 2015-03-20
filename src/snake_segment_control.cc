#include "snake_segment_control.hh"
#include <memory>
#include <utility>
#include "abstract_factory.hh"
#include "snake_segment_output.hh"
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
snake_segment_control::snake_segment_control(abstract_factory* factory)
: snake_segment_control{factory->make_snake_segment_output()} {}

snake_segment_control::snake_segment_control(
  std::unique_ptr<snake_segment_output> out)
: snake_segment_control{std::move(out),
                        rectangle{position{0, 0}, width{10}, height{10}}} {}

snake_segment_control::snake_segment_control(
  std::unique_ptr<snake_segment_output> out, rectangle rect)
: out{std::move(out)}, rect{std::move(rect)} {}
}
