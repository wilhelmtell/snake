#include "sdl_berry_output.hh"
#include "game_control.hh"

namespace snk {
void sdl_berry_output::controlled_by(game_control* const control) {
  this->control = control;
}
}
