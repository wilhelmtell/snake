#include <catch/catch.hpp>
#include <memory>
#include "../src/snake_control.hh"
#include "mock_snake_output.hh"

TEST_CASE("snake is initially at origin") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  REQUIRE(out->position_initialized);
  REQUIRE(out->x == 0);
  REQUIRE(out->y == 0);
}

TEST_CASE("snake initially moves right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  control.update();
  control.draw();
  REQUIRE(out->x == 1);
  REQUIRE(out->y == 0);
}
