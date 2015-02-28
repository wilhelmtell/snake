#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "mock_game_view.hh"
#include "quit_game_view.hh"

TEST_CASE("game is initially on") {
  snk::test::mock_game_view view;
  snk::game_control control{&view};
  REQUIRE(control.is_on());
}

TEST_CASE("upon quit, game is no longer on") {
  snk::test::quit_game_view view;
  snk::game_control control{&view};
  view.control(&control);
  control.tick();
  REQUIRE(!control.is_on());
}
