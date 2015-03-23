#include "sdl_game_output.hh"
#include <SDL2/SDL.h>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
sdl_game_output::sdl_game_output(SDL_Window* w, SDL_Renderer* r)
: w{w}, r{r} {}

void sdl_game_output::clear(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
  SDL_RenderClear(this->r);
}

void sdl_game_output::present() { SDL_RenderPresent(r); }

rectangle sdl_game_output::bounds() const {
  rectangle rect{point{0, 0}, width{0}, height{0}};
  SDL_GL_GetDrawableSize(w, &rect.w, &rect.h);
  return rect;
}
}
