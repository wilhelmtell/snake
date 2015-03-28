#include "sdl.hh"
#include "event_dispatch.hh"
#include <SDL2/SDL.h>

namespace {
void quit() {
  SDL_Event sdl_quit_event;
  SDL_zero(sdl_quit_event);
  sdl_quit_event.type = SDL_QUIT;
  SDL_PushEvent(&sdl_quit_event);
}
}

namespace snk {
sdl::sdl(event_dispatch* dispatch)
: subsystem{SDL_INIT_VIDEO}, ttf_subsystem{} {
  dispatch->on_quit(quit);
}
}
