#include "renderer.hh"
#include <SDL2/SDL.h>
#include "renderer_creation_error.hh"
#include "window.hh"

namespace snk {
renderer::renderer(window const& w)
: r{SDL_CreateRenderer(
      w.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
    &SDL_DestroyRenderer} {
  if(r == nullptr) throw renderer_creation_error(SDL_GetError());
}

SDL_Renderer* renderer::get() const { return r.get(); }
}
