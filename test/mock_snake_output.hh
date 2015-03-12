#ifndef SNK_TEST_SNAKE_OUTPUT_HH_
#define SNK_TEST_SNAKE_OUTPUT_HH_

#include "../src/snake_output.hh"

namespace snk {
namespace test {
struct mock_snake_output : snk::snake_output {
  bool at_position(int x, int y) const;

  void draw_rect(int x, int y, int w, int h) override;

private:
  int x, y;
  int w, h;
};
}
}

#endif
