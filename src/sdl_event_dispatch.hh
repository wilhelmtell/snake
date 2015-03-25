#ifndef SNK_SDL_EVENT_DISPATCH_HH_
#define SNK_SDL_EVENT_DISPATCH_HH_

#include "event_dispatch_fwd.hh"
#include <SDL2/SDL.h>

namespace snk {
void handle_event(event_dispatch const& dispatch, SDL_Event const& e);
}

#endif
