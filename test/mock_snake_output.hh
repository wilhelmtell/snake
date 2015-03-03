#ifndef SNK_TEST_SNAKE_OUTPUT_HH_
#define SNK_TEST_SNAKE_OUTPUT_HH_

#include "../src/snake_output.hh"

namespace snk {
namespace test {
struct mock_snake_output : snk::snake_output {
  bool at_position(int x, int y) const;

  void position(int x, int y);

private:
  int x, y;
};
}
}

#endif
