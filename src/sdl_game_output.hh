#ifndef SNK_SDL_GAME_OUTPUT_HH_
#define SNK_SDL_GAME_OUTPUT_HH_

#include "game_output.hh"
#include "game_control_fwd.hh"

namespace snk {
struct sdl_game_output : game_output {
  void controlled_by(game_control* const control);

private:
  game_control* control;
};
}

#endif
