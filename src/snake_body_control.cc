#include "snake_body_control.hh"
#include <utility>
#include "abstract_factory.hh"
#include "event_dispatch.hh"
#include "snake_segment_control.hh"
#include "direction.hh"
#include "point.hh"
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
    return snk::point{position.x - default_segment_width, position.y};
  case snk::direction::right:
    return snk::point{position.x + default_segment_width, position.y};
  case snk::direction::up:
    return snk::point{position.x, position.y - default_segment_height};
  default:
    return snk::point{position.x, position.y + default_segment_height};
  }
}
}

namespace snk {
snake_body_control::snake_body_control(event_dispatch* dispatch,
                                       abstract_factory* factory)
: snake_body_control{
    dispatch, std::move(factory), factory->make_snake_body_output()} {}

snake_body_control::snake_body_control(event_dispatch* dispatch,
                                       abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out)
: snake_body_control{
    dispatch, std::move(factory), std::move(out), direction::right} {}

snake_body_control::snake_body_control(event_dispatch* dispatch,
                                       abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out,
                                       direction move_request)
: dispatch{dispatch}
, factory{std::move(factory)}
, out{std::move(out)}
, move_requests{}
, move_to{move_request}
, segments{} {
  dispatch->on_berry_eaten([&](auto const& p) { on_berry_eaten(p); });
  dispatch->on_keydown_left([&]() { on_keydown_left(); });
  dispatch->on_keydown_right([&]() { on_keydown_right(); });
  dispatch->on_keydown_up([&]() { on_keydown_up(); });
  dispatch->on_keydown_down([&]() { on_keydown_down(); });
  move_requests.push_back(move_request);
  segments.emplace_back(dispatch,
                        this->factory,
                        default_segment_position,
                        default_segment_width,
                        default_segment_height);
}

void snake_body_control::update() {
  auto const next_move = fetch_next_move();
  move_to = are_opposite(move_to, next_move) ? move_to : next_move;
  segments.emplace_front(dispatch,
                         factory,
                         factory->make_snake_segment_output(),
                         moved(segments.front().position(), move_to),
                         default_segment_width,
                         default_segment_height);
  segments.pop_back();
  for(auto& segment : segments) segment.update();
}

void snake_body_control::draw() const {
  for(auto const& segment : segments) segment.draw();
}

void snake_body_control::restart() {
  segments.clear();
  segments.emplace_front(dispatch,
                         factory,
                         default_segment_position,
                         default_segment_width,
                         default_segment_height);
  move_requests.clear();
  move_requests.push_back(direction::right);
  move_to = direction::right;
  dispatch->game_restarted();
}

direction snake_body_control::fetch_next_move_request() {
  auto const move_requested = move_requests.front();
  move_requests.pop_front();
  return move_requested;
}

direction snake_body_control::fetch_next_move() {
  return move_requests.empty() ? move_to : fetch_next_move_request();
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

void snake_body_control::on_berry_eaten(point const& /*position*/) {
  segments.emplace_back(dispatch,
                        factory,
                        segments.back().position(),
                        default_segment_width,
                        default_segment_height);
}

void snake_body_control::on_keydown_left() {
  move_requests.push_back(direction::left);
}

void snake_body_control::on_keydown_right() {
  move_requests.push_back(direction::right);
}

void snake_body_control::on_keydown_up() {
  move_requests.push_back(direction::up);
}

void snake_body_control::on_keydown_down() {
  move_requests.push_back(direction::down);
}
}
