#include <catch/catch.hpp>
#include "mock_snake_output.hh"
#include "../src/snake_control.hh"

TEST_CASE("snake is initially at origin") {
  snk::test::mock_snake_output output;
  snk::snake_control control{&output};
  REQUIRE(output.at_position(0, 0));
}
