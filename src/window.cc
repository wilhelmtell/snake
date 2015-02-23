#include "window.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"

namespace snk {
auto const WINDOW_W = 640;
auto const WINDOW_H = 480;
}

namespace snk {
window::window()
: w{SDL_CreateWindow("Snake",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     WINDOW_W,
                     WINDOW_H,
                     SDL_WINDOW_SHOWN),
    &SDL_DestroyWindow} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

SDL_Window* window::get() const { return w.get(); }
}