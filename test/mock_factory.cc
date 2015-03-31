#include "mock_factory.hh"
#include <memory>
#include <utility>
#include "mock_game_output.hh"
#include "mock_snake_output.hh"
#include "mock_snake_body_output.hh"
#include "mock_snake_segment_output.hh"
#include "mock_berry_output.hh"
#include "mock_snake_direction_output.hh"

namespace snk {
namespace test {
mock_factory::mock_factory(rectangle bounds) : bounds{std::move(bounds)} {}

std::unique_ptr<snk::game_output> mock_factory::make_game_output() const {
  return std::make_unique<mock_game_output>(bounds);
}

std::unique_ptr<snk::snake_output> mock_factory::make_snake_output() const {
  return std::make_unique<mock_snake_output>();
}

std::unique_ptr<snake_body_output> mock_factory::make_snake_body_output()
  const {
  return std::make_unique<mock_snake_body_output>(bounds);
}

std::unique_ptr<snake_segment_output> mock_factory::make_snake_segment_output()
  const {
  return std::make_unique<mock_snake_segment_output>();
}

std::unique_ptr<snk::berry_output> mock_factory::make_berry_output() const {
  return std::make_unique<mock_berry_output>(bounds);
}

std::unique_ptr<snk::snake_direction_output>
mock_factory::make_snake_direction_output() const {
  return std::make_unique<mock_snake_direction_output>();
}
}
}
