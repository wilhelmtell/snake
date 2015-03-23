#include "snake_body_control.hh"
#include <utility>
#include "abstract_factory.hh"
#include "event.hh"
#include "snake_segment_control.hh"
#include "direction.hh"
#include <stdexcept>

namespace {
snk::point const default_segment_position{0, 0};
snk::width const default_segment_width{10};
snk::height const default_segment_height{10};
}

namespace {
snk::point moved(snk::point const& position, snk::direction const& towards) {
  switch(towards) {
  case snk::direction::left:
    return snk::point{position.x - default_segment_width.get(), position.y};
  case snk::direction::right:
    return snk::point{position.x + default_segment_width.get(), position.y};
  case snk::direction::up:
    return snk::point{position.x, position.y - default_segment_height.get()};
  case snk::direction::down:
    return snk::point{position.x, position.y + default_segment_height.get()};
  default:
    throw std::logic_error{
      "unexpected direction in computing near() position"};
  }
}

snk::direction to_direction(snk::event const& e,
                            snk::direction const& otherwise) {
  switch(e) {
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
}

namespace snk {
snake_body_control::snake_body_control(abstract_factory* factory)
: snake_body_control{std::move(factory), factory->make_snake_body_output()} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out)
: snake_body_control{std::move(factory), std::move(out), direction::right} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out,
                                       direction move_request)
: factory{std::move(factory)}
, out{std::move(out)}
, move_requested{move_request}
, move_to{std::move(move_request)}
, segments{}
, grow{false} {
  segments.emplace_back(this->factory,
                        default_segment_position,
                        default_segment_width,
                        default_segment_height);
}

void snake_body_control::handle_event(event const& e) {
  move_requested = to_direction(e, move_requested);
  for(auto& segment : segments) segment.handle_event(e);
}

void snake_body_control::update() {
  move_to = are_opposite(move_to, move_requested) ? move_to : move_requested;
  segments.emplace_front(factory->make_snake_segment_output(),
                         moved(segments.front().position(), move_to),
                         default_segment_width,
                         default_segment_height);
  if(!grow) segments.pop_back();
  grow = false;
  for(auto& segment : segments) segment.update();
}

void snake_body_control::draw() const {
  for(auto const& segment : segments) segment.draw();
}

bool snake_body_control::dead() const {
  return segments.front().intersect(out->bounds());
}
}
