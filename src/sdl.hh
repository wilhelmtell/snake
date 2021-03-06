#ifndef SNK_SDL_HH_
#define SNK_SDL_HH_

#include "sdl_system.hh"
#include "sdl_ttf_system.hh"
#include "event_dispatch_fwd.hh"

namespace snk {
struct sdl {
  explicit sdl(event_dispatch* dispatch);

private:
  sdl_system subsystem;
  sdl_ttf_system ttf_subsystem;
};
}

#endif
