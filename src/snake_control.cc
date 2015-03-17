#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"
#include "position.hh"
#include "rectangle.hh"
#include "snake_segment.hh"
#include <stdexcept>

namespace {
snk::direction to_move_request(snk::event const& e,
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

snk::direction next_move_from_move_requested(snk::direction previous,
                                             snk::direction move_requested) {
  using dir = snk::direction;
  switch(move_requested.type) {
  case dir::up: return previous == dir::down ? dir::down : dir::up;
  case dir::right: return previous == dir::left ? dir::left : dir::right;
  case dir::down: return previous == dir::up ? dir::up : dir::down;
  case dir::left: return previous == dir::right ? dir::right : dir::left;
  default: throw std::logic_error("unexpected move request");
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
: snake_control{std::move(out), std::move(seg), direction::right} {}

snake_control::snake_control(std::unique_ptr<snake_output> out,
                             snake_segment seg,
                             direction first_move)
: out{std::move(out)}
, seg{std::move(seg)}
, move_requested{std::move(first_move)}
, next_move{std::move(first_move)}
, expired{false} {}

  void snake_control::handle_event(event const& e) {
  move_requested = to_move_request(e, move_requested);
}

void snake_control::update() {
  if(dead()) return;
  next_move = next_move_from_move_requested(next_move, move_requested);
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
