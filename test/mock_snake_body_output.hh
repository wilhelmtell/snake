#ifndef SNK_TEST_MOCK_SNAKE_BODY_OUTPUT_HH_
#define SNK_TEST_MOCK_SNAKE_BODY_OUTPUT_HH_

#include "../src/snake_body_output.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
struct mock_snake_body_output : snk::snake_body_output {
  explicit mock_snake_body_output(rectangle bounding_rect);

  rectangle bounds() const override;

private:
  rectangle bounding_rect;
};
}
}

#endif
