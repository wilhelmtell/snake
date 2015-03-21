#include "mock_snake_body_output.hh"
#include "rectangle.hh"
#include <utility>

namespace snk {
namespace test {
mock_snake_body_output::mock_snake_body_output(rectangle bounds)
: bounds{std::move(bounds)} {}

rectangle mock_snake_body_output::get_drawable_size() const {
  return bounds;
}
}
}
