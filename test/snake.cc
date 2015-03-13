#include <catch/catch.hpp>
#include <memory>
#include "../src/snake_control.hh"
#include "mock_snake_output.hh"
#include "event.hh"

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

TEST_CASE("snake moving right won't move left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  control.update();
  control.draw();
  snk::event e{snk::event::keydown_left};
  control.handle_event(e);
  control.update();
  control.draw();
  REQUIRE(out->x == 2);
  REQUIRE(out->y == 0);
}

TEST_CASE("snake moving right can move down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  control.update();
  control.draw();
  snk::event e{snk::event::keydown_down};
  control.handle_event(e);
  control.update();
  control.draw();
  REQUIRE(out->x == 1);
  REQUIRE(out->y == 1);
}
