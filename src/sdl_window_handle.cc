#include "sdl_window_handle.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"

namespace snk {
sdl_window_handle::sdl_window_handle(char const* const title,
                                     int const& x,
                                     int const& y,
                                     int const& width,
                                     int const& height,
                                     int const& flags)
: w{SDL_CreateWindow(title, x, y, width, height, flags), &SDL_DestroyWindow} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

SDL_Window* sdl_window_handle::get() const { return w.get(); }
}
