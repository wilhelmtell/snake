#include "quit_factory.hh"
#include <memory>
#include "quit_game_input.hh"
#include "quit_game_output.hh"
#include "quit_window_input.hh"
#include "quit_window_output.hh"
#include "quit_snake_input.hh"
#include "quit_snake_output.hh"

namespace snk {
namespace test {
std::unique_ptr<snk::game_input> quit_factory::make_game_input() const {
  return std::make_unique<quit_game_input>();
}

std::unique_ptr<snk::game_output> quit_factory::make_game_output() const {
  return std::make_unique<quit_game_output>();
}

std::unique_ptr<snk::window_input> quit_factory::make_window_input() const {
  return std::make_unique<quit_window_input>();
}

std::unique_ptr<snk::window_output> quit_factory::make_window_output() const {
  return std::make_unique<quit_window_output>();
}

std::unique_ptr<snk::snake_input> quit_factory::make_snake_input() const {
  return std::make_unique<quit_snake_input>();
}

std::unique_ptr<snk::snake_output> quit_factory::make_snake_output() const {
  return std::make_unique<quit_snake_output>();
}
}
}
