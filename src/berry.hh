#ifndef SNK_BERRY_HH_
#define SNK_BERRY_HH_

#include <SDL2/SDL.h>
#include "game.hh"

namespace snk {
extern int const BERRY_H;
extern int const BERRY_W;
extern unsigned int const BERRY_INTERVAL;  // in ms

struct berry {
  void update(game const& g, SDL_Event const& e);
  void draw() const;

private:
  SDL_Rect rect;
};
}

#endif
