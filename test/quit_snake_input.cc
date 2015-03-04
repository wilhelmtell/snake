#include "quit_snake_input.hh"

namespace snk {
namespace test {
void quit_snake_input::controlled_by(snake_control* control) {
  this->control = control;
}

void quit_snake_input::tick() {}
}
}
