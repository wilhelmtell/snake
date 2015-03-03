#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include "noop_game_input.hh"
#include "noop_game_output.hh"
#include "quit_game_input.hh"
#include "quit_game_output.hh"
#include "mock_window_output.hh"

TEST_CASE("game is initially on") {
  snk::test::noop_game_input input;
  snk::test::noop_game_output output;
  snk::test::mock_window_output w_o;
  snk::game_control control{&input, &output, &w_o};
  REQUIRE(control.is_on());
}

TEST_CASE("upon quit, game is no longer on") {
  snk::test::quit_game_input input;
  snk::test::quit_game_output output;
  snk::test::mock_window_output w_o;
  snk::game_control control{&input, &output, &w_o};
  output.controlled_by(&control);
  control.tick();
  REQUIRE(!control.is_on());
}
