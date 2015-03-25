#include "snake_body_control.hh"
#include <utility>
#include "abstract_factory.hh"
#include "event_dispatch.hh"
#include "snake_segment_control.hh"
#include "direction.hh"
#include "point.hh"
#include <stdexcept>
#include <algorithm>
#include <iterator>

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
}

namespace snk {
snake_body_control::snake_body_control(abstract_factory* factory,
                                       event_dispatch* dispatch)
: snake_body_control{
    std::move(factory), factory->make_snake_body_output(), dispatch} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out,
                                       event_dispatch* dispatch)
: snake_body_control{
    std::move(factory), std::move(out), dispatch, direction::right} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out,
                                       event_dispatch* dispatch,
                                       direction move_request)
: factory{std::move(factory)}
, out{std::move(out)}
, dispatch{dispatch}
, move_requested{move_request}
, move_to{std::move(move_request)}
, segments{} {
  dispatch->on_berry_eaten([=](point const& /*position*/) {
    segments.emplace_back(factory,
                          dispatch,
                          segments.back().position(),
                          default_segment_width,
                          default_segment_height);
  });
  dispatch->on_keydown_left([&]() { move_requested = direction::left; });
  dispatch->on_keydown_right([&]() { move_requested = direction::right; });
  dispatch->on_keydown_up([&]() { move_requested = direction::up; });
  dispatch->on_keydown_down([&]() { move_requested = direction::down; });
  segments.emplace_back(this->factory,
                        dispatch,
                        default_segment_position,
                        default_segment_width,
                        default_segment_height);
}

void snake_body_control::update() {
  move_to = are_opposite(move_to, move_requested) ? move_to : move_requested;
  segments.emplace_front(factory->make_snake_segment_output(),
                         dispatch,
                         moved(segments.front().position(), move_to),
                         default_segment_width,
                         default_segment_height);
  segments.pop_back();
  for(auto& segment : segments) segment.update();
}

void snake_body_control::draw() const {
  for(auto const& segment : segments) segment.draw();
}

bool snake_body_control::wall_hit() const {
  return segments.front().outside(out->bounds());
}

bool snake_body_control::self_hit() const {
  auto const& head = segments.front();
  auto const min = 5;  // minimum length necessary for self collision
  if(segments.size() < min) return false;
  auto const b = next(begin(segments), min - 1);
  auto const e = end(segments);
  return std::find_if(b, e, [&](auto const& s) { return head.hit(s); }) != e;
}

bool snake_body_control::dead() const { return wall_hit() || self_hit(); }

point snake_body_control::head_position() const {
  return segments.front().position();
}
}
