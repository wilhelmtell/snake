#ifndef SNK_TEST_SNAKE_OUTPUT_HH_
#define SNK_TEST_SNAKE_OUTPUT_HH_

#include "../src/snake_output.hh"
#include "../src/position.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
struct mock_snake_output : snk::snake_output {
  mock_snake_output();

  bool at_position(position const& pos) const;

  rectangle get_drawable_size() override;
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(position pos, rectangle rect) override;

public:
  bool position_initialized;
  position pos;
  snk::rectangle rect;
};
}
}

#endif
