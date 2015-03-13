#include "mock_factory.hh"
#include <memory>
#include "mock_game_output.hh"
#include "mock_snake_output.hh"
#include "mock_berry_output.hh"

namespace snk {
namespace test {
std::unique_ptr<snk::game_output> mock_factory::make_game_output() const {
  return std::make_unique<mock_game_output>();
}

std::unique_ptr<snk::snake_output> mock_factory::make_snake_output() const {
  return std::make_unique<mock_snake_output>();
}

std::unique_ptr<snk::berry_output> mock_factory::make_berry_output() const {
  return std::make_unique<mock_berry_output>();
}
}
}