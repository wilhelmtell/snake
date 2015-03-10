#include <catch/catch.hpp>
#include "mock_factory.hh"
#include "quit_factory.hh"
#include "../src/game_control.hh"

TEST_CASE("game is initially on") {
  snk::test::mock_factory factory;
  snk::game_control control{factory};
  // REQUIRE(!control.quit_requested());
}

TEST_CASE("upon quit, game is no longer on") {
  snk::test::quit_factory factory;
  snk::game_control control{factory};
  // control.tick();
  // REQUIRE(control.quit_requested());
}
