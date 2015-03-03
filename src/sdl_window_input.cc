#include "sdl_window_input.hh"
#include "window_control.hh"

namespace snk {
void sdl_window_input::controlled_by(window_control* control) {
  this->control = control;
}
}
