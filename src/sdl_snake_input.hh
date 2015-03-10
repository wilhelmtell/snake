#ifndef SNK_SDL_SNAKE_INPUT_HH_
#define SNK_SDL_SNAKE_INPUT_HH_

#include "snake_input.hh"
#include "snake_control_fwd.hh"

namespace snk {
struct sdl_snake_input : snake_input {
  explicit sdl_snake_input(snake_control* const control);
};
}

#endif
