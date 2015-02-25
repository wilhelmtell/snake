#ifndef SNK_GAME_HH_
#define SNK_GAME_HH_

#include "sdl.hh"
#include <SDL2/SDL.h>
#include "window.hh"
#include "renderer.hh"
#include "snake.hh"
#include "berry.hh"

namespace snk {
struct game {
  game();

  void handle_event(SDL_Event const& e);
  void update();
  void draw() const;

  int window_w() const;
  int window_h() const;

private:
  sdl sdl_subsystem;
  window w;
  renderer r;
  snake s;
  berry b;
};
}

#endif
