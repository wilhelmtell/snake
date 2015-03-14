#include "sdl_snake_output.hh"
#include "rectangle.hh"
#include "position.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_output::sdl_snake_output(SDL_Renderer* r, SDL_Window* w)
: r{r}, w{w} {}

void sdl_snake_output::get_drawable_size(rectangle* rect) {
  SDL_GL_GetDrawableSize(this->w, &rect->w, &rect->h);
}

void sdl_snake_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
}

void sdl_snake_output::draw_rect(position pos, int w, int h) {
  SDL_Rect rect{pos.x, pos.y, w, h};
  SDL_RenderFillRect(r, &rect);
}
}
