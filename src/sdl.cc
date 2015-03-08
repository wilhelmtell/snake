#include "sdl.hh"
#include <SDL2/SDL.h>
#include <utility>

namespace snk {
sdl::sdl() : owning{true} { SDL_Init(SDL_INIT_VIDEO); }

sdl::sdl(sdl&& rhs) : owning{rhs.owning} { rhs.owning = false; }

sdl& sdl::operator=(sdl&& rhs) {
  using std::swap;
  swap(owning, rhs.owning);
  return *this;
}

sdl::~sdl() {
  if(owning) SDL_Quit();
}
}
