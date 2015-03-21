#include "sdl_snake_body_output.hh"
#include <utility>
#include <SDL2/SDL.h>
#include "rectangle.hh"

namespace snk {
sdl_snake_body_output::sdl_snake_body_output(SDL_Window* window,
                                             SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}

rectangle sdl_snake_body_output::get_drawable_size() const {
  rectangle rect;
  SDL_GL_GetDrawableSize(window, &rect.w, &rect.h);
  return rect;
}
}
