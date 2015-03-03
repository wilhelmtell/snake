#ifndef SNK_SDL_BERRY_VIEW_HH_
#define SNK_SDL_BERRY_VIEW_HH_

#include "berry_view.hh"
#include "game_control_fwd.hh"

namespace snk {
struct sdl_berry_view : berry_view {
  void controlled_by(game_control* const control);

private:
  game_control* control;
};
}

#endif
