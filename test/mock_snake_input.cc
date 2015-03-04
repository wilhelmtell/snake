#include "mock_snake_input.hh"

namespace snk {
namespace test {
void mock_snake_input::controlled_by(snake_control* control) {
  this->control = control;
}

void mock_snake_input::tick() {}
}
}
