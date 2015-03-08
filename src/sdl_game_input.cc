#include "sdl_game_input.hh"
#include "game_control.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_game_input::sdl_game_input(game_control* const control)
: control{control} {}

void sdl_game_input::tick() {
  for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
    if(e.type == SDL_QUIT) control->notify_end();
  }
}
}
