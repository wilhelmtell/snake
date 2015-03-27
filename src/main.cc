#include "config.h"
#include <SDL2/SDL.h>
#include "sdl_app.hh"

namespace {
auto const milliseconds_per_frame = 1.0 / 60 * 1000;
}

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_app app;
  auto previous_timestamp = SDL_GetTicks();
  auto lag = 0.0;
  while(true) {
    auto const current_timestamp = SDL_GetTicks();
    auto const elapsed = current_timestamp - previous_timestamp;
    previous_timestamp = current_timestamp;
    lag += elapsed;
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if(e.type == SDL_QUIT) return 0;
      app.handle_event(e);
    }
    while(lag >= milliseconds_per_frame) {
      app.update();
      lag -= milliseconds_per_frame;
    }
    app.draw();
  }
}
