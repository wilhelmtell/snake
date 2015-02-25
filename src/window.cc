#include "window.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"

namespace snk {
window::window(int const& width, int const& height)
: w{SDL_CreateWindow("Snake",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     width,
                     height,
                     SDL_WINDOW_SHOWN),
    &SDL_DestroyWindow} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

SDL_Window* window::get() const { return w.get(); }
}
