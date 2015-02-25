#ifndef SNK_SNAKE_HH_
#define SNK_SNAKE_HH_

#include <SDL2/SDL.h>
#include "game_fwd.hh"
#include "renderer_fwd.hh"

namespace snk {
struct snake {
  snake();

  void update(game const& g, SDL_Event const& e);
  void draw(renderer const& r) const;

private:
  SDL_Rect rect;
};
}

#endif
