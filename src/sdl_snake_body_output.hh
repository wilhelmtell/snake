#ifndef SNK_SDL_SNAKE_BODY_OUTPUT_HH_
#define SNK_SDL_SNAKE_BODY_OUTPUT_HH_

#include "snake_body_output.hh"
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"

namespace snk {
struct sdl_snake_body_output : snake_body_output {
  sdl_snake_body_output(SDL_Window* window, SDL_Renderer* renderer);

  rectangle get_drawable_size() const override;

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}

#endif
