#ifndef SNK_SDL_EVENT_TO_EVENT_HH_
#define SNK_SDL_EVENT_TO_EVENT_HH_

#include <SDL2/SDL.h>
#include "event_fwd.hh"

namespace snk {
event to_keydown_event(SDL_Event const& e);
event to_event(SDL_Event const& e);
}

#endif
