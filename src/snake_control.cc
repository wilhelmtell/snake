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
: snake_control{std::move(out), std::move(pos), rectangle{25, 25}} {}

snake_control::snake_control(std::unique_ptr<snake_output> out,
                             position pos,
                             rectangle rect)
: out{std::move(out)}
, direction{-1}
, pos{std::move(pos)}
, rect{std::move(rect)}
, expired{false} {}

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
  if(dead()) return;
  auto const drawable_rect = out->get_drawable_size();
  if(direction == 1 && pos.x + rect.w < drawable_rect.w)
    ++pos.x;
  else if(direction == 3 && pos.x > 0)
    --pos.x;
  else if(direction == 3 && pos.x == 0)
    expired = true;  // left turn against the wall: we're dead
  else if(direction == 0 && pos.y > 0)
    --pos.y;
  else if(direction == 0 && pos.y == 0)
    expired = true;  // up turn against the wall: we're dead
  else if(direction == 2 && pos.y + rect.h < drawable_rect.h)
    ++pos.y;
}

void snake_control::draw() {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(pos, rect);
}

bool snake_control::dead() const { return expired; }
}
