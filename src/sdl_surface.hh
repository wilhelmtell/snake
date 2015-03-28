#ifndef SNK_SDL_SURFACE_HH_
#define SNK_SDL_SURFACE_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
struct sdl_surface {
  explicit sdl_surface(SDL_Surface* s);

  SDL_Surface* get() const;

private:
  using pointer = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
  pointer s;
};
}

#endif
