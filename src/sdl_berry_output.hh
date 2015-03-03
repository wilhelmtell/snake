#ifndef SNK_SDL_BERRY_OUTPUT_HH_
#define SNK_SDL_BERRY_OUTPUT_HH_

#include "berry_output.hh"
#include "game_control_fwd.hh"

namespace snk {
struct sdl_berry_output : berry_output {
  void controlled_by(game_control* const control);

private:
  game_control* control;
};
}

#endif
