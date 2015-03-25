#include "sdl_event_dispatch.hh"
#include "event_dispatch.hh"
#include <SDL2/SDL.h>
#include <cassert>

namespace {
void handle_keydown_event(snk::event_dispatch const& dispatch,
                          SDL_Event const& e) {
  assert(e.type == SDL_KEYDOWN);
  if(e.key.keysym.sym == SDLK_ESCAPE) dispatch.keydown_esc();
  else if(e.key.keysym.sym == SDLK_p) dispatch.keydown_p();
  else if(e.key.keysym.sym == SDLK_LEFT) dispatch.keydown_left();
  else if(e.key.keysym.sym == SDLK_RIGHT) dispatch.keydown_right();
  else if(e.key.keysym.sym == SDLK_UP) dispatch.keydown_up();
  else if(e.key.keysym.sym == SDLK_DOWN) dispatch.keydown_down();
}
}

namespace snk {
void handle_event(event_dispatch const& dispatch, SDL_Event const& e) {
  if(e.type == SDL_QUIT)
    dispatch.quit();
  else if(e.type == SDL_KEYDOWN)
    handle_keydown_event(dispatch, e);
}
}
