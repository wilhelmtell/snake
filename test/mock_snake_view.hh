#ifndef SNK_TEST_SNAKE_VIEW_HH_
#define SNK_TEST_SNAKE_VIEW_HH_

#include "../src/snake_view.hh"

namespace snk {
namespace test {
struct mock_snake_view : snk::snake_view {
  bool at_position(int x, int y) const;

  void position(int x, int y);

private:
  int x, y;
};
}
}

#endif
