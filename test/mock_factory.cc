#include "mock_factory.hh"
#include <memory>
#include "mock_game_input.hh"
#include "mock_game_output.hh"
#include "mock_window_input.hh"
#include "mock_window_output.hh"
#include "mock_snake_input.hh"
#include "mock_snake_output.hh"

namespace snk {
namespace test {
std::unique_ptr<snk::game_input> mock_factory::make_game_input() const {
  return std::make_unique<mock_game_input>();
}

std::unique_ptr<snk::game_output> mock_factory::make_game_output() const {
  return std::make_unique<mock_game_output>();
}

std::unique_ptr<snk::window_input> mock_factory::make_window_input() const {
  return std::make_unique<mock_window_input>();
}

std::unique_ptr<snk::window_output> mock_factory::make_window_output() const {
  return std::make_unique<mock_window_output>();
}

std::unique_ptr<snk::snake_input> mock_factory::make_snake_input() const {
  return std::make_unique<mock_snake_input>();
}

std::unique_ptr<snk::snake_output> mock_factory::make_snake_output() const {
  return std::make_unique<mock_snake_output>();
}
}
}
