#include "sdl_renderer_handle.hh"
#include <SDL2/SDL.h>
#include "renderer_creation_error.hh"
#include "sdl_window_handle.hh"

namespace snk {
sdl_renderer_handle::sdl_renderer_handle(sdl_window_handle const& w,
                                         int const& index,
                                         int const& flags)
: r{SDL_CreateRenderer(w.get(), index, flags), &SDL_DestroyRenderer} {
  if(r == nullptr) throw renderer_creation_error(SDL_GetError());
}

SDL_Renderer* sdl_renderer_handle::get() const { return r.get(); }
}
