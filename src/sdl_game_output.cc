#include "sdl_game_output.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_game_output::sdl_game_output(SDL_Renderer* r) : r{r} {}

void sdl_game_output::present() { SDL_RenderPresent(r); }
}
