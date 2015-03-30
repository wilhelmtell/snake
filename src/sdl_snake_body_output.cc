#include "sdl_snake_body_output.hh"
#include <utility>
#include <SDL2/SDL.h>
#include "rectangle.hh"

namespace snk {
sdl_snake_body_output::sdl_snake_body_output(SDL_Window* window,
                                             SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}

rectangle sdl_snake_body_output::bounds() const {
  int w, h;
  SDL_GL_GetDrawableSize(window, &w, &h);
  return rectangle{point{0, 0}, width{w}, height{h}};
}
}
