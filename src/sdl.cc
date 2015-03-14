#include "sdl.hh"
#include <SDL2/SDL.h>
#include <utility>
#include "sdl_init_error.hh"

namespace snk {
sdl::sdl(int const& flags) : owning{true} {
  if(SDL_Init(flags) < 0) throw sdl_init_error{SDL_GetError()};
}

sdl::sdl(sdl&& rhs) : owning{std::move(rhs.owning)} { rhs.owning = false; }

sdl& sdl::operator=(sdl&& rhs) {
  owning = rhs.owning;
  rhs.owning = false;
  return *this;
}

sdl::~sdl() { SDL_Quit(); }
}
