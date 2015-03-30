#include "sdl_berry_output.hh"
#include <utility>
#include "rectangle.hh"
#include "point.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_berry_output::sdl_berry_output(SDL_Window* window, SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}

void sdl_berry_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void sdl_berry_output::draw_rect(rectangle const& rect) {
  SDL_Rect sdl_rect{rect.p.x, rect.p.y, rect.w, rect.h};
  SDL_RenderFillRect(renderer, &sdl_rect);
}

rectangle sdl_berry_output::bounds() const {
  int w, h;
  SDL_GL_GetDrawableSize(window, &w, &h);
  return rectangle{point{0, 0}, width{w}, height{h}};
}
}
