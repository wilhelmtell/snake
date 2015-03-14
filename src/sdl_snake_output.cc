#include "sdl_snake_output.hh"
#include "rectangle.hh"
#include "position.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_output::sdl_snake_output(SDL_Renderer* r, SDL_Window* w)
: r{r}, w{w} {}

rectangle sdl_snake_output::get_drawable_size() {
  rectangle rect;
  SDL_GL_GetDrawableSize(w, &rect.w, &rect.h);
  return rect;
}

void sdl_snake_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
}

void sdl_snake_output::draw_rect(position pos, rectangle rect) {
  SDL_Rect sdl_rect{pos.x, pos.y, rect.w, rect.h};
  SDL_RenderFillRect(r, &sdl_rect);
}
}
