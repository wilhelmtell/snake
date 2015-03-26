#include "config.h"
#include <SDL2/SDL.h>
#include "sdl_app.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_app app;
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if(e.type == SDL_QUIT) return 0;
      app.handle_event(e);
    }
    app.update();
    app.draw();
    SDL_Delay(100);
  }
}
