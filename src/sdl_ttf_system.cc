#include "sdl_ttf_system.hh"
#include <SDL2/SDL_ttf.h>
#include <utility>
#include "sdl_ttf_system_init_error.hh"

namespace snk {
sdl_ttf_system::sdl_ttf_system() : owning{true} {
  if(TTF_Init() < 0) throw sdl_ttf_system_init_error{TTF_GetError()};
}

sdl_ttf_system::sdl_ttf_system(sdl_ttf_system&& rhs)
: owning{std::move(rhs.owning)} {
  rhs.owning = false;
}

sdl_ttf_system& sdl_ttf_system::operator=(sdl_ttf_system&& rhs) {
  owning = rhs.owning;
  rhs.owning = false;
  return *this;
}

sdl_ttf_system::~sdl_ttf_system() { TTF_Quit(); }
}
