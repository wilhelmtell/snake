#include "config.h"
#include "game.hh"
#include <SDL2/SDL.h>

int main(int /*argc*/, char * /*argv*/ []) {
  snk::game g;
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if( e.type == SDL_QUIT ) return 0;
      g.update(e);
      g.draw();
    }
  }
}
