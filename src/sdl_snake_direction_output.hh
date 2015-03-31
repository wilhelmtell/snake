#ifndef SNK_SDL_SNAKE_DIRECTION_OUTPUT_HH_
#define SNK_SDL_SNAKE_DIRECTION_OUTPUT_HH_

#include "snake_direction_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_snake_direction_output : snake_direction_output {
  sdl_snake_direction_output(SDL_Window* window, SDL_Renderer* renderer);

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}

#endif
