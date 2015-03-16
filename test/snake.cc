#include <catch/catch.hpp>
#include <memory>
#include "../src/snake_control.hh"
#include "mock_snake_output.hh"
#include "event.hh"
#include "../src/position.hh"
#include "position_to_string.hh"

TEST_CASE("snake by default is initially at origin") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  REQUIRE(out->position_initialized);
  REQUIRE(out->pos == snk::position(0, 0));
}

TEST_CASE("snake originally doesn't move") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 0));
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 0));
}

TEST_CASE("pressing left-arrow key moves snake left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 1));
}

TEST_CASE("pressing right-arrow key moves snake right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 1));
}

TEST_CASE("pressing down-arrow key moves snake down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(1, 2));
}

TEST_CASE("pressing up-arrow key moves snake up") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(1, 0));
}

TEST_CASE("snake moving right won't move left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.handle_event(snk::event::keydown_right);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 0));  // snake moved to the right again
}

TEST_CASE("snake moving left won't move right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_left);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 2));  // snake moved to the left again
}

TEST_CASE("snake moving down won't move up") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_down);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 4));  // snake moved to the left again
}

TEST_CASE("snake moving up won't move down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_up);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 0));  // snake moved to the left again
}

TEST_CASE("snake moving right can move down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out)};
  control.handle_event(snk::event::keydown_right);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(1, 1));
}

TEST_CASE("snake moving right can move up") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_right);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 0));
}

TEST_CASE("moving right is a no-op when snake is already moving right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_right);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(3, 1));
}

TEST_CASE("snake moving left can move down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_left);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 2));
}

TEST_CASE("snake moving left can move up") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_left);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 0));
}

TEST_CASE("moving left is a no-op when snake is already moving left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_left);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 2));
}

TEST_CASE("snake moving down can move left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_down);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 2));
}

TEST_CASE("snake moving down can move right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_down);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 2));
}

TEST_CASE("moving down is a no-op when snake is already moving down") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_down);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 4));
}

TEST_CASE("snake moving up can move left") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_up);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(0, 0));
}

TEST_CASE("snake moving up can move right") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{1, 1}};
  control.handle_event(snk::event::keydown_up);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 0));
}

TEST_CASE("moving up is a no-op when snake is already moving up") {
  auto control_out = std::make_unique<snk::test::mock_snake_output>();
  auto out = control_out.get();
  snk::snake_control control{std::move(control_out), snk::position{2, 2}};
  control.handle_event(snk::event::keydown_up);
  control.update();  // must update or else arrow key press is ignored
  control.draw();
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(out->pos == snk::position(2, 0));
}

TEST_CASE("left against the wall kills snake") {
  snk::snake_control control{std::make_unique<snk::test::mock_snake_output>(),
                             snk::position{0, 0}};
  control.handle_event(snk::event::keydown_left);
  control.update();
  control.draw();
  REQUIRE(control.dead());
}

TEST_CASE("up against the wall kills snake") {
  snk::snake_control control{std::make_unique<snk::test::mock_snake_output>(),
                             snk::position{0, 0}};
  control.handle_event(snk::event::keydown_up);
  control.update();
  control.draw();
  REQUIRE(control.dead());
}

TEST_CASE("right against the wall kills snake") {
  snk::rectangle drawable_rect{10, 10};
  auto control_out
    = std::make_unique<snk::test::mock_snake_output>(drawable_rect);
  auto out = control_out.get();
  snk::rectangle const snake_rect{2, 2};
  snk::snake_control control{
    std::move(control_out),
    snk::position{out->get_drawable_size().w - snake_rect.w, 0},
    snake_rect};
  control.handle_event(snk::event::keydown_right);
  control.update();
  control.draw();
  REQUIRE(control.dead());
}

TEST_CASE("down against the wall kills snake") {
  snk::rectangle drawable_rect{10, 10};
  auto control_out
    = std::make_unique<snk::test::mock_snake_output>(drawable_rect);
  auto out = control_out.get();
  snk::rectangle const snake_rect{2, 2};
  snk::snake_control control{
    std::move(control_out),
    snk::position{0, out->get_drawable_size().h - snake_rect.h},
    snake_rect};
  control.handle_event(snk::event::keydown_down);
  control.update();
  control.draw();
  REQUIRE(control.dead());
}
