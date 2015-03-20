#include "sdl_snake_output.hh"
#include "rectangle.hh"
#include "position.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_output::sdl_snake_output(SDL_Window* w, SDL_Renderer* r)
: w{w}, r{r} {}

rectangle sdl_snake_output::get_drawable_size() const {
  rectangle rect;
  SDL_GL_GetDrawableSize(w, &rect.w, &rect.h);
  return rect;
}

void sdl_snake_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
}

void sdl_snake_output::draw_rect(rectangle const& rect) {
  SDL_Rect sdl_rect{rect.p.x, rect.p.y, rect.w, rect.h};
  SDL_RenderFillRect(r, &sdl_rect);
}
}
