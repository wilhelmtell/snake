#include "sdl_game_output.hh"
#include "game_control.hh"
#include <SDL2/SDl.h>

namespace snk {
void sdl_game_output::controlled_by(game_control* const control) {
  this->control = control;
}
}
