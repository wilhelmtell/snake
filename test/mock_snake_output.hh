#ifndef SNK_TEST_SNAKE_OUTPUT_HH_
#define SNK_TEST_SNAKE_OUTPUT_HH_

#include "../src/snake_output.hh"
#include "../src/position.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
struct mock_snake_output : snk::snake_output {
  mock_snake_output();
  explicit mock_snake_output(snk::rectangle const& drawable_rect);

  bool at_position(snk::position const& pos) const;

  snk::rectangle get_drawable_size() override;
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(snk::position const& pos,
                 snk::rectangle const& rect) override;

public:
  bool position_initialized;
  snk::rectangle drawable_rect;
  snk::position pos;
  snk::rectangle rect;
};
}
}

#endif
