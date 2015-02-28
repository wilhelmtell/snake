#ifndef SNK_SDL_SNAKE_VIEW_HH_
#define SNK_SDL_SNAKE_VIEW_HH_

#include "snake_view.hh"

namespace snk {
struct sdl_snake_view : snake_view {
  void position(int x, int y);
};
}

#endif
