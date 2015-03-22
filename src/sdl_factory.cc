#include "sdl_factory.hh"
#include "sdl_window.hh"
#include <memory>
#include "sdl_game_output.hh"
#include "sdl_snake_output.hh"
#include "sdl_snake_body_output.hh"
#include "sdl_snake_segment_output.hh"
#include "sdl_berry_output.hh"
#include "point.hh"
#include "rectangle.hh"

namespace snk {
sdl_factory::sdl_factory()
: s{SDL_INIT_VIDEO}
, w{"Snake",
    rectangle{point{SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED},
              width{640},
              height{480}},
    SDL_WINDOW_SHOWN}
, r{this->w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC} {}

std::unique_ptr<game_output> sdl_factory::make_game_output() const {
  return std::make_unique<sdl_game_output>(r.get());
}

std::unique_ptr<snake_output> sdl_factory::make_snake_output() const {
  return std::make_unique<sdl_snake_output>(w.get(), r.get());
}

std::unique_ptr<snake_body_output> sdl_factory::make_snake_body_output()
  const {
  return std::make_unique<sdl_snake_body_output>(w.get(), r.get());
}

std::unique_ptr<snake_segment_output> sdl_factory::make_snake_segment_output()
  const {
  return std::make_unique<sdl_snake_segment_output>(w.get(), r.get());
}

std::unique_ptr<berry_output> sdl_factory::make_berry_output() const {
  return std::make_unique<sdl_berry_output>(r.get());
}
}
