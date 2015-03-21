#include "mock_snake_body_output.hh"
#include "rectangle.hh"
#include <utility>

namespace snk {
namespace test {
mock_snake_body_output::mock_snake_body_output(rectangle bounding_rect)
: bounding_rect{std::move(bounding_rect)} {}

rectangle mock_snake_body_output::bounds() const {
  return bounding_rect;
}
}
}
