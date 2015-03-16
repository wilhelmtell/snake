#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"
#include "position.hh"
#include "rectangle.hh"
#include "snake_segment.hh"

namespace {
snk::direction to_arrow_key_press(snk::event const& e,
                                  snk::direction default_value) {
  using dir = snk::direction;
  switch(e.type) {
  case snk::event::keydown_up: return dir::up;
  case snk::event::keydown_right: return dir::right;
  case snk::event::keydown_down: return dir::down;
  case snk::event::keydown_left: return dir::left;
  default: return default_value;
  }
}

snk::direction next_move_from_arrow_key_press(snk::direction previous,
                                              snk::direction arrow_key) {
  using dir = snk::direction;
  switch(arrow_key.type) {
  case dir::up: return previous == dir::down ? dir::down : dir::up;
  case dir::right: return previous == dir::left ? dir::left : dir::right;
  case dir::down: return previous == dir::up ? dir::up : dir::down;
  case dir::left: return previous == dir::right ? dir::right : dir::left;
  default: return dir::nil;
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
, arrow_key_press{direction::nil}
, next_move{direction::nil}
, seg{std::move(seg)}
, expired{false} {}

void snake_control::handle_event(event const& e) {
  arrow_key_press = to_arrow_key_press(e, arrow_key_press);
}

void snake_control::update() {
  if(dead()) return;
  next_move = next_move_from_arrow_key_press(next_move, arrow_key_press);
  auto const drawable_rect = out->get_drawable_size();
  if(next_move == direction::right && seg.pos.x + seg.rect.w < drawable_rect.w)
    ++seg.pos.x;
  else if(next_move == direction::right
          && seg.pos.x + seg.rect.w == drawable_rect.w)
    expired = true;
  else if(next_move == direction::left && seg.pos.x > 0)
    --seg.pos.x;
  else if(next_move == direction::left && seg.pos.x == 0)
    expired = true;  // left turn against the wall: we're dead
  else if(next_move == direction::up && seg.pos.y > 0)
    --seg.pos.y;
  else if(next_move == direction::up && seg.pos.y == 0)
    expired = true;  // up turn against the wall: we're dead
  else if(next_move == direction::down
          && seg.pos.y + seg.rect.h < drawable_rect.h)
    ++seg.pos.y;
  else if(next_move == direction::down
          && seg.pos.y + seg.rect.h == drawable_rect.h)
    expired = true;
}

void snake_control::draw() {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(seg.pos, seg.rect);
}

bool snake_control::dead() const { return expired; }
}
