#include "sdl_berry_view.hh"
#include "game_control.hh"

namespace snk {
void sdl_berry_view::controlled_by(game_control* const control) {
  this->control = control;
}
}
