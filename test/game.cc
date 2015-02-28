#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "mock_game_view.hh"

TEST_CASE("game") {
  snk::test::mock_game_view view;
  snk::game_control control{&view};
}
