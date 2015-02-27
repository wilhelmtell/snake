#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "mock_game_view.hh"
#include <memory>

TEST_CASE("game") {
  auto const view = std::make_unique<snk::test::mock_game_view>();
  snk::game_control control{view.get()};
}
