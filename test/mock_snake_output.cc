#include "mock_snake_output.hh"

namespace snk {
namespace test {
bool mock_snake_output::at_position(int x, int y) const {
  return x == this->x && y == this->y;
}

void mock_snake_output::position(int x, int y) {
  this->x = x;
  this->y = y;
}
}
}
