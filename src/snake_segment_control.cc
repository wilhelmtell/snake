#include "snake_segment_control.hh"
#include <memory>
#include <utility>
#include "abstract_factory.hh"
#include "snake_segment_output.hh"
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"
#include "point.hh"
#include "event.hh"
#include "direction.hh"

namespace {
snk::point const default_segment_position{0, 0};
snk::width const default_segment_width{10};
snk::height const default_segment_height{10};

snk::direction to_direction(snk::event const& e,
                            snk::direction const& otherwise) {
  switch(e.type) {
  case snk::event::keydown_left:
    return snk::direction::left;
  case snk::event::keydown_right:
    return snk::direction::right;
  case snk::event::keydown_up:
    return snk::direction::up;
  case snk::event::keydown_down:
    return snk::direction::down;
  default:
    return otherwise;
  }
}

snk::rectangle move_left(snk::rectangle const& rect) {
  return snk::rectangle{snk::point{rect.p.x - rect.w, rect.p.y},
                        snk::width{rect.w},
                        snk::height{rect.h}};
}

snk::rectangle move_right(snk::rectangle const& rect) {
  return snk::rectangle{snk::point{rect.p.x + rect.w, rect.p.y},
                        snk::width{rect.w},
                        snk::height{rect.h}};
}

snk::rectangle move_up(snk::rectangle const& rect) {
  return snk::rectangle{snk::point{rect.p.x, rect.p.y - rect.h},
                        snk::width{rect.w},
                        snk::height{rect.h}};
}

snk::rectangle move_down(snk::rectangle const& rect) {
  return snk::rectangle{snk::point{rect.p.x, rect.p.y + rect.h},
                        snk::width{rect.w},
                        snk::height{rect.h}};
}

snk::rectangle move_segment_rect(snk::rectangle const& rect,
                                 snk::direction to) {
  switch(to) {
  case snk::direction::left:
    return move_left(rect);
  case snk::direction::right:
    return move_right(rect);
  case snk::direction::up:
    return move_up(rect);
  case snk::direction::down:
    return move_down(rect);
  default:
    return rect;
  }
}
}

namespace snk {
snake_segment_control::snake_segment_control(abstract_factory* factory)
: snake_segment_control{factory->make_snake_segment_output()} {}

snake_segment_control::snake_segment_control(
  std::unique_ptr<snake_segment_output> out)
: snake_segment_control{
    std::move(out),
    rectangle{
      default_segment_position, default_segment_width, default_segment_height},
    direction::right} {}

snake_segment_control::snake_segment_control(
  std::unique_ptr<snake_segment_output> out,
  rectangle rect,
  direction move_requested)
: out{std::move(out)}
, rect{std::move(rect)}
, move_requested{move_requested}
, move_to{std::move(move_requested)} {}

void snake_segment_control::handle_event(event const& e) {
  move_requested = to_direction(e, move_requested);
}

void snake_segment_control::update() {
  move_to = are_opposite(move_to, move_requested) ? move_to : move_requested;
  rect = move_segment_rect(rect, move_to);
}

void snake_segment_control::draw() const {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(rect);
}

bool snake_segment_control::intersect(rectangle const& rect) const {
  return snk::intersect(this->rect, rect);
}
}
