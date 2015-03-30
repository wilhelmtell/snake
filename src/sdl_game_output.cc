#include "sdl_game_output.hh"
#include <SDL2/SDL.h>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
sdl_game_output::sdl_game_output(SDL_Window* window, SDL_Renderer* renderer)
: window{window}, renderer{renderer} {}

void sdl_game_output::clear(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderClear(renderer);
}

void sdl_game_output::present() { SDL_RenderPresent(renderer); }

rectangle sdl_game_output::bounds() const {
  int w, h;
  SDL_GL_GetDrawableSize(window, &w, &h);
  return rectangle{point{0, 0}, width{w}, height{h}};
}
}
