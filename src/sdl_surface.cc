#include "sdl_surface.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_surface::sdl_surface(SDL_Surface* s) : s{s, SDL_FreeSurface} {}

SDL_Surface* sdl_surface::get() const { return s.get(); }
}
