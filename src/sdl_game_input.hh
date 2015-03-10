#ifndef SNK_SDL_GAME_INPUT_HH_
#define SNK_SDL_GAME_INPUT_HH_

#include "game_input.hh"
#include "game_control_fwd.hh"

namespace snk {
struct sdl_game_input : game_input {
  explicit sdl_game_input(game_control* const control);

private:
  game_control* control;
};
}

#endif
