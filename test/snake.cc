#include <catch/catch.hpp>
#include <memory>
#include "../src/snake_control.hh"
#include "mock_snake_input.hh"
#include "mock_snake_output.hh"

TEST_CASE("snake is initially at origin") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::make_unique<snk::test::mock_snake_input>(),
                             std::move(control_out)};
  REQUIRE(out->at_position(0, 0));
}
