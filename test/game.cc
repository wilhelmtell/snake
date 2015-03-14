#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include <memory>
#include "mock_game_output.hh"
#include "mock_factory.hh"

TEST_CASE("esc quits the game") {
  snk::game_control control{std::make_unique<snk::test::mock_game_output>(),
                            snk::test::mock_factory()};
  control.handle_event(snk::event::keydown_esc);
  control.update();
  control.draw();
  REQUIRE(control.game_over());
}
