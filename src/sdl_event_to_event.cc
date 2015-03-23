#include "sdl_event_to_event.hh"
#include <SDL2/SDL.h>
#include "event.hh"

namespace snk {
event to_keydown_event(SDL_Event const& e) {
  switch(e.key.keysym.sym) {
  case SDLK_LEFT: return event::keydown_left;
  case SDLK_RIGHT: return event::keydown_right;
  case SDLK_UP: return event::keydown_up;
  case SDLK_DOWN: return event::keydown_down;
  case SDLK_ESCAPE: return event::keydown_esc;
  default: return event::unknown;
  }
}

event to_event(SDL_Event const& e) {
  switch(e.type) {
  case SDL_KEYDOWN: return to_keydown_event(e);
  default: return event::unknown;
  }
}
}
