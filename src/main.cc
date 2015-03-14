#include "config.h"
#include "sdl_factory.hh"
#include "game_control.hh"
#include <SDL2/SDL.h>
#include "sdl_event_to_event.hh"
#include "event.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_factory factory;
  snk::game_control control{factory};
  while(!control.game_over()) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if(e.type == SDL_QUIT) return 0;
      control.handle_event(snk::to_event(e));
    }
    control.update();
    control.draw();
  }
}
