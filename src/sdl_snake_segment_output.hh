#ifndef SNK_SDL_SNAKE_SEGMENT_OUTPUT_HH_
#define SNK_SDL_SNAKE_SEGMENT_OUTPUT_HH_

#include "snake_segment_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_snake_segment_output : snake_segment_output {
  sdl_snake_segment_output(SDL_Window* window, SDL_Renderer* renderer);

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}

#endif
