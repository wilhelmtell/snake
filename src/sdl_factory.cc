#include "sdl_factory.hh"
#include "event_dispatch.hh"
#include "sdl_window.hh"
#include <memory>
#include "sdl_game_output.hh"
#include "sdl_snake_output.hh"
#include "sdl_snake_body_output.hh"
#include "sdl_snake_segment_output.hh"
#include "sdl_berry_output.hh"
#include "point.hh"
#include "rectangle.hh"

namespace {
void quit() {
  SDL_Event sdl_quit_event;
  SDL_zero(sdl_quit_event);
  sdl_quit_event.type = SDL_QUIT;
  SDL_PushEvent(&sdl_quit_event);
}
}

namespace snk {
sdl_factory::sdl_factory(event_dispatch* dispatch)
: sdl{SDL_INIT_VIDEO}
, window{"Snake",
         rectangle{point{SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED},
                   width{640},
                   height{480}},
         SDL_WINDOW_SHOWN}
, renderer{
    this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC} {
  dispatch->on_quit(quit);
}

std::unique_ptr<game_output> sdl_factory::make_game_output() const {
  return std::make_unique<sdl_game_output>(window.get(), renderer.get());
}

std::unique_ptr<snake_output> sdl_factory::make_snake_output() const {
  return std::make_unique<sdl_snake_output>(window.get(), renderer.get());
}

std::unique_ptr<snake_body_output> sdl_factory::make_snake_body_output()
  const {
  return std::make_unique<sdl_snake_body_output>(window.get(), renderer.get());
}

std::unique_ptr<snake_segment_output> sdl_factory::make_snake_segment_output()
  const {
  return std::make_unique<sdl_snake_segment_output>(window.get(),
                                                    renderer.get());
}

std::unique_ptr<berry_output> sdl_factory::make_berry_output() const {
  return std::make_unique<sdl_berry_output>(window.get(), renderer.get());
}
}
