#ifndef SNK_SNAKE_HH_
#define SNK_SNAKE_HH_

#include <SDL2/SDL.h>
#include "game.hh"

namespace snk {
struct snake {
  void update(game const& g, SDL_Event const& e);
  void draw() const;

private:
  SDL_Rect rect;
};
}

#endif
