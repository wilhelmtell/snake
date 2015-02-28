#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "noop_game_view.hh"
#include "quit_game_view.hh"

TEST_CASE("game is initially on") {
  snk::test::noop_game_view view;
  snk::game_control control{&view};
  REQUIRE(control.is_on());
}

TEST_CASE("upon quit, game is no longer on") {
  snk::test::quit_game_view view;
  snk::game_control control{&view};
  view.controlled_by(&control);
  control.tick();
  REQUIRE(!control.is_on());
}
