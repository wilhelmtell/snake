#ifndef SNK_SDL_SNAKE_OUTPUT_HH_
#define SNK_SDL_SNAKE_OUTPUT_HH_

#include "snake_output.hh"

namespace snk {
struct sdl_snake_output : snake_output {
  void position(int x, int y);
};
}

#endif
