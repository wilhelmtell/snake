#include "sdl_snake_output.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_output::sdl_snake_output(SDL_Renderer* r, SDL_Window* w)
: r{r}, w{w} {}

void sdl_snake_output::get_drawable_size(int* w, int* h) {
  SDL_GL_GetDrawableSize(this->w, w, h);
}

void sdl_snake_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
}

void sdl_snake_output::draw_rect(int x, int y, int w, int h) {
  SDL_Rect rect{x, y, w, h};
  SDL_RenderFillRect(r, &rect);
}
}
