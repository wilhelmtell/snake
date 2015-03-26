#ifndef SNK_SDL_APP_HH_
#define SNK_SDL_APP_HH_

#include "event_dispatch.hh"
#include "sdl.hh"
#include "sdl_factory.hh"
#include "game_control.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_app {
  sdl_app();

  void handle_event(SDL_Event const& e);
  void update();
  void draw() const;

private:
  event_dispatch dispatch;
  snk::sdl sdl;
  sdl_factory factory;
  game_control game;
};
}

#endif
