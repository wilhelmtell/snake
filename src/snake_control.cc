#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"
#include "position.hh"
#include "rectangle.hh"

namespace snk {
snake_control::snake_control(abstract_factory const& factory)
: snake_control{factory.make_snake_output()} {}

snake_control::snake_control(std::unique_ptr<snake_output> out)
: snake_control{std::move(out), position{0, 0}} {}

snake_control::snake_control(std::unique_ptr<snake_output> out, position pos)
: out{std::move(out)}, direction{-1}, pos{std::move(pos)}, w{25}, h{25} {}

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
  snk::rectangle drawable_rect;
  out->get_drawable_size(&drawable_rect);
  if(direction == 1 && pos.x + w < drawable_rect.w)
    ++pos.x;
  else if(direction == 3 && pos.x > 0)
    --pos.x;
  if(direction == 0 && pos.y > 0)
    --pos.y;
  else if(direction == 2 && pos.y + h < drawable_rect.h)
    ++pos.y;
}

void snake_control::draw() {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(pos, w, h);
}
}
