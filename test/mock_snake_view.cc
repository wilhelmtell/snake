#include "mock_snake_view.hh"

namespace snk {
namespace test {
bool mock_snake_view::at_position(int x, int y) const {
  return x == this->x && y == this->y;
}

void mock_snake_view::position(int x, int y) {
  this->x = x;
  this->y = y;
}
}
}
