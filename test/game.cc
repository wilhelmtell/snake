#include <catch/catch.hpp>
#include "../src/game_control.hh"
#include <memory>
#include "mock_game_output.hh"
#include "mock_factory.hh"
#include "../src/rectangle.hh"
#include "../src/width.hh"
#include "../src/height.hh"
#include "../src/point.hh"

TEST_CASE("esc quits the game") {
  snk::point const origin{0, 0};
  snk::rectangle const bounds{origin, snk::width{100}, snk::height{100}};
  snk::test::mock_factory factory{bounds};
  snk::game_control control{
    std::make_unique<snk::test::mock_game_output>(bounds), &factory};
  control.handle_event(snk::event::keydown_esc);
  control.update();
  control.draw();
  REQUIRE(control.game_over());
}
