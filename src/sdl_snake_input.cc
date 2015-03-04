#include "sdl_snake_input.hh"

namespace snk {
void sdl_snake_input::controlled_by(snake_control* control) {
  this->control = control;
}

void sdl_snake_input::tick() {}
}
