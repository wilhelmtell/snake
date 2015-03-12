#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"

namespace snk {
snake_control::snake_control(abstract_factory const& factory)
: out{factory.make_snake_output()}, direction{1}, x{0}, y{0} {}

snake_control::snake_control(std::unique_ptr<snake_output> out)
: out{std::move(out)} {}

void snake_control::handle_event(event const& e) {
  if(e.type == event::keydown_left && direction != 1) {
    direction = 3;
  } else if(e.type == event::keydown_right && direction != 3) {
    direction = 1;
  } else if(e.type == event::keydown_up && direction != 2) {
    direction = 0;
  } else if(e.type == event::keydown_down && direction != 0) {
    direction = 2;
  }
}

void snake_control::update() {
  if(direction == 1)
    ++x;
  else if(direction == 3)
    --x;
  if(direction == 0)
    --y;
  else if(direction == 2)
    ++y;
}

void snake_control::draw() {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(x, y, 25, 25);
}
}
