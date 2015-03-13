#ifndef SNK_SDL_BERRY_OUTPUT_HH_
#define SNK_SDL_BERRY_OUTPUT_HH_

#include "berry_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_berry_output : berry_output {
  explicit sdl_berry_output(SDL_Renderer* renderer);
};
}

#endif
