#ifndef SNK_MOCK_SNAKE_SEGMENT_OUTPUT_HH_
#define SNK_MOCK_SNAKE_SEGMENT_OUTPUT_HH_

#include "../src/snake_segment_output.hh"
#include "../src/rectangle_fwd.hh"

namespace snk {
namespace test {
struct mock_snake_segment_output : snk::snake_segment_output {
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(snk::rectangle const& rect) override;
};
}
}

#endif
