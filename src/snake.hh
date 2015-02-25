#ifndef SNK_SNAKE_HH_
#define SNK_SNAKE_HH_

#include <SDL2/SDL.h>
#include "game_fwd.hh"
#include "renderer_fwd.hh"

namespace snk {
struct snake {
  snake();

  void handle_event(game const& g, SDL_Event const& e);
  void update(game const& g);
  void draw(renderer const& r) const;

private:
  SDL_Rect rect;
  unsigned int last_move_time;
  int velx;
  int vely;
};
}

#endif
