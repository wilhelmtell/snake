#include <catch/catch.hpp>
#include "mock_snake_view.hh"
#include "../src/snake_control.hh"

TEST_CASE("snake is initially at origin") {
  snk::test::mock_snake_view view;
  snk::snake_control control{&view};
  REQUIRE(view.at_position(0, 0));
}
