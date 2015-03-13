#include "sdl_game_output.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_game_output::sdl_game_output(SDL_Renderer* r) : r{r} {}

void sdl_game_output::clear(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->r, r, g, b, a);
  SDL_RenderClear(this->r);
}

void sdl_game_output::present() { SDL_RenderPresent(r); }
}
