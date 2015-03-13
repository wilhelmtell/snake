#include "sdl_window.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"
#include "position.hh"

namespace snk {
sdl_window::sdl_window(char const* const title,
                       position const& pos,
                       int const& width,
                       int const& height,
                       int const& flags)
: w{SDL_CreateWindow(title, pos.x, pos.y, width, height, flags),
    &SDL_DestroyWindow} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

SDL_Window* sdl_window::get() const { return w.get(); }
}
