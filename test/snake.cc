#include <catch/catch.hpp>
#include "mock_snake_view.hh"
#include "../src/snake_control.hh"

TEST_CASE("snake movement") {
  snk::test::mock_snake_view view;
  snk::snake_control control{&view};
  SECTION("snake is initially at origin") { REQUIRE(view.at_position(0, 0)); }
}
