#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "noop_game_view.hh"
#include "quit_game_view.hh"
#include "mock_window_view.hh"

TEST_CASE("game is initially on") {
  snk::test::noop_game_view view;
  snk::test::mock_window_view w_v;
  snk::game_control control{&view, &w_v};
  REQUIRE(control.is_on());
}

TEST_CASE("upon quit, game is no longer on") {
  snk::test::quit_game_view view;
  snk::test::mock_window_view w_v;
  snk::game_control control{&view, &w_v};
  view.controlled_by(&control);
  control.tick();
  REQUIRE(!control.is_on());
}
