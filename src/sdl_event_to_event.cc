#include "sdl_event_to_event.hh"
#include <SDL2/SDL.h>
#include "event.hh"

namespace snk {
event to_keydown_event(SDL_Event const& e) {
  switch(e.key.keysym.sym) {
  case SDLK_LEFT: return event{event::keydown_left};
  case SDLK_RIGHT: return event{event::keydown_right};
  case SDLK_UP: return event{event::keydown_up};
  case SDLK_DOWN: return event{event::keydown_down};
  default: return event{event::unknown};
  }
}

event to_event(SDL_Event const& e) {
  switch(e.type) {
  case SDL_KEYDOWN: return to_keydown_event(e);
  default: return event{event::unknown};
  }
}
}