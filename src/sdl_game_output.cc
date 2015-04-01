#include "sdl_game_output.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
sdl_game_output::sdl_game_output(SDL_Window* /*window*/,
                                 SDL_Renderer* renderer)
: renderer{renderer} {}

void sdl_game_output::clear(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderClear(renderer);
}

void sdl_game_output::present() { SDL_RenderPresent(renderer); }
}
