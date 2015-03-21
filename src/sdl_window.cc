#include "sdl_window.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"
#include "rectangle.hh"

namespace snk {
sdl_window::sdl_window(char const* const title,
                       rectangle const& bounds,
                       int const& flags)
: w{SDL_CreateWindow(title, bounds.p.x, bounds.p.y, bounds.w, bounds.h, flags),
    &SDL_DestroyWindow} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

SDL_Window* sdl_window::get() const { return w.get(); }
}
