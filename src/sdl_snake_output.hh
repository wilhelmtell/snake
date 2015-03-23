#ifndef SNK_SDL_SNAKE_OUTPUT_HH_
#define SNK_SDL_SNAKE_OUTPUT_HH_

#include "snake_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_snake_output : snake_output {
  sdl_snake_output(SDL_Window* window, SDL_Renderer* renderer);
};
}

#endif
