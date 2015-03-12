#include "sdl_snake_output.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_output::sdl_snake_output(SDL_Renderer* r) : r{r} {}

void sdl_snake_output::draw_rect(int x, int y, int w, int h) {
  SDL_Rect rect{x, y, w, h};
  SDL_RenderFillRect(r, &rect);
}
}
