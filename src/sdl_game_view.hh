#ifndef SNK_SDL_GAME_VIEW_HH_
#define SNK_SDL_GAME_VIEW_HH_

#include "game_view.hh"
#include "game_control_fwd.hh"

namespace snk {
struct sdl_game_view : game_view {
  void controlled_by(game_control* const control);
  void tick();

private:
  game_control* control;
};
}

#endif
