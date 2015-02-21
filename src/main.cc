#include "config.h"
#include "sdl.hh"
#include <SDL2/SDL.h>
#include <iostream>

int main(int /*argc*/, char * /*argv*/ []) {
  snk::sdl app;
  if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    std::cerr << "error: linear texturing filtering not enabled.\n";
    return 1;
  }
}
