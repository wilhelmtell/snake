#include <catch/catch.hpp>
#include "mock_snake_view.hh"
#include "../src/snake_control.hh"
#include <memory>

TEST_CASE("snake movement") {
  auto const view = std::make_unique<snk::test::mock_snake_view>();
  snk::snake_control control{view.get()};
  SECTION("snake is initially at origin") { REQUIRE(view->at_position(0, 0)); }
}
