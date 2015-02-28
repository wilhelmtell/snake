#include "sdl_game_view.hh"
#include "game_control.hh"
#include <SDL2/SDl.h>

namespace snk {
void sdl_game_view::controlled_by(game_control* const control) {
  this->control = control;
}

void sdl_game_view::tick() {
  for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
    if(e.type == SDL_QUIT) control->notify_end();
  }
}
}
