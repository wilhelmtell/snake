#include "config.h"
#include <SDL2/SDL.h>
#include "sdl_app.hh"
#include <chrono>

namespace {
using clock = std::chrono::system_clock;
auto const target_frames_per_second = 60;
auto const time_per_frame = clock::duration{static_cast<clock::rep>(
  1.0 / target_frames_per_second * clock::period::den)};
}

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_app app;
  auto previous_timestamp = clock::now();
  clock::duration lag{0};
  while(true) {
    auto const current_timestamp = clock::now();
    auto const elapsed_time = current_timestamp - previous_timestamp;
    previous_timestamp = current_timestamp;
    lag += elapsed_time;
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if(e.type == SDL_QUIT) return 0;
      app.handle_event(e);
    }
    while(lag >= time_per_frame) {
      app.update();
      lag -= time_per_frame;
    }
    app.draw();
  }
}
