#include "config.h"
#include "sdl.hh"
#include "sdl_factory.hh"
#include "game_control.hh"
#include <SDL2/SDL.h>
#include "event_dispatch.hh"
#include "sdl_event_dispatch.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::event_dispatch dispatch;
  snk::sdl sdl{&dispatch};
  snk::sdl_factory factory;
  snk::game_control control{&factory, &dispatch};
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      handle_event(dispatch, e);
      if(e.type == SDL_QUIT) return 0;
    }
    control.update();
    control.draw();
    SDL_Delay(100);
  }
}
