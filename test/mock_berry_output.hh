#ifndef SNK_TEST_MOCK_BERRY_OUTPUT_HH_
#define SNK_TEST_MOCK_BERRY_OUTPUT_HH_

#include "../src/berry_output.hh"
#include "../src/rectangle_fwd.hh"

namespace snk {
namespace test {
struct mock_berry_output : berry_output {
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(rectangle const& rect) override;
};
}
}

#endif
