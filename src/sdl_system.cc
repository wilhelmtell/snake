#include "sdl_system.hh"
#include <SDL2/SDL.h>
#include <utility>
#include "sdl_system_init_error.hh"

namespace snk {
sdl_system::sdl_system(int const& flags) : owning{true} {
  if(SDL_Init(flags) < 0) throw sdl_system_init_error{SDL_GetError()};
}

sdl_system::sdl_system(sdl_system&& rhs) : owning{std::move(rhs.owning)} {
  rhs.owning = false;
}

sdl_system& sdl_system::operator=(sdl_system&& rhs) {
  owning = rhs.owning;
  rhs.owning = false;
  return *this;
}

sdl_system::~sdl_system() { SDL_Quit(); }
}
