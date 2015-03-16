#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"
#include "position.hh"
#include "rectangle.hh"
#include "snake_segment.hh"

namespace {
int to_arrow_key_press(snk::event const& e, int default_value) {
  switch(e.type) {
  case snk::event::keydown_up: return 0;
  case snk::event::keydown_right: return 1;
  case snk::event::keydown_down: return 2;
  case snk::event::keydown_left: return 3;
  default: return default_value;
  }
}

int direction_from_arrow_key_press(int previous_direction, int arrow_key) {
  switch(arrow_key) {
  case 0: return previous_direction == 2 ? 2 : 0;
  case 1: return previous_direction == 3 ? 3 : 1;
  case 2: return previous_direction == 0 ? 0 : 2;
  case 3: return previous_direction == 1 ? 1 : 3;
  default: return -1;
  }
}
}

namespace snk {
snake_control::snake_control(abstract_factory* factory)
: snake_control{factory->make_snake_output()} {}

snake_control::snake_control(std::unique_ptr<snake_output> out)
: snake_control{std::move(out),
                snake_segment{position{0, 0}, rectangle{25, 25}}} {}

snake_control::snake_control(std::unique_ptr<snake_output> out,
                             snake_segment seg)
: out{std::move(out)}
, arrow_key_press{-1}
, direction{-1}
, seg{std::move(seg)}
, expired{false} {}

void snake_control::handle_event(event const& e) {
  arrow_key_press = to_arrow_key_press(e, arrow_key_press);
}

void snake_control::update() {
  if(dead()) return;
  direction = direction_from_arrow_key_press(direction, arrow_key_press);
  auto const drawable_rect = out->get_drawable_size();
  if(direction == 1 && seg.pos.x + seg.rect.w < drawable_rect.w)
    ++seg.pos.x;
  else if(direction == 1 && seg.pos.x + seg.rect.w == drawable_rect.w)
    expired = true;
  else if(direction == 3 && seg.pos.x > 0)
    --seg.pos.x;
  else if(direction == 3 && seg.pos.x == 0)
    expired = true;  // left turn against the wall: we're dead
  else if(direction == 0 && seg.pos.y > 0)
    --seg.pos.y;
  else if(direction == 0 && seg.pos.y == 0)
    expired = true;  // up turn against the wall: we're dead
  else if(direction == 2 && seg.pos.y + seg.rect.h < drawable_rect.h)
    ++seg.pos.y;
  else if(direction == 2 && seg.pos.y + seg.rect.h == drawable_rect.h)
    expired = true;
}

void snake_control::draw() {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(seg.pos, seg.rect);
}

bool snake_control::dead() const { return expired; }
}
