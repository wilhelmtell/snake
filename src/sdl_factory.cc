#include "sdl_factory.hh"
#include <memory>
#include "sdl_game_output.hh"
#include "sdl_window_output.hh"
#include "sdl_snake_output.hh"
#include "sdl_berry_output.hh"

namespace snk {
std::unique_ptr<game_output> sdl_factory::make_game_output() const {
  return std::make_unique<sdl_game_output>();
}

std::unique_ptr<window_output> sdl_factory::make_window_output() const {
  return std::make_unique<sdl_window_output>(640, 480);
}

std::unique_ptr<snake_output> sdl_factory::make_snake_output() const {
  return std::make_unique<sdl_snake_output>();
}

std::unique_ptr<berry_output> sdl_factory::make_berry_output() const {
  return std::make_unique<sdl_berry_output>();
}
}
