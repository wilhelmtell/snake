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
auto const default_initial_snake_length = 3;
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

std::deque<snk::snake_segment_control> initial_snake_segments(
  snk::event_dispatch* dispatch, snk::abstract_factory* factory) {
  std::deque<snk::snake_segment_control> segments;
  for(int i = 0; i != default_initial_snake_length; ++i) {
    segments.emplace_back(
      dispatch,
      factory,
      snk::point{default_segment_width * (default_initial_snake_length - i
                                          - default_segment_position.x - 1),
                 default_segment_position.y},
      default_segment_width,
      default_segment_height);
  }
  return segments;
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
, segments{initial_snake_segments(dispatch, factory)}
, keydown_left_connection{
    dispatch->on_keydown_left([&]() { on_move(direction::left); })}
, keydown_right_connection{
    dispatch->on_keydown_right([&]() { on_move(direction::right); })}
, keydown_up_connection{
    dispatch->on_keydown_up([&]() { on_move(direction::up); })}
, keydown_down_connection{
    dispatch->on_keydown_down([&]() { on_move(direction::down); })} {
  dispatch->on_game_paused([&]() { on_game_paused(); });
  dispatch->on_game_resumed([&]() { on_game_resumed(); });
  dispatch->on_berry_eaten([&](auto const& p) { on_berry_eaten(p); });
  move_requests.push_back(move_request);
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
  segments = initial_snake_segments(dispatch, factory);
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

void snake_body_control::on_move(direction const& to) {
  move_requests.push_back(to);
}

void snake_body_control::on_game_paused() {
  keydown_left_connection.disconnect();
  keydown_right_connection.disconnect();
  keydown_up_connection.disconnect();
  keydown_down_connection.disconnect();
}

void snake_body_control::on_game_resumed() {
  keydown_left_connection
    = dispatch->on_keydown_left([&]() { on_move(direction::left); });
  keydown_right_connection
    = dispatch->on_keydown_right([&]() { on_move(direction::right); });
  keydown_up_connection
    = dispatch->on_keydown_up([&]() { on_move(direction::up); });
  keydown_down_connection
    = dispatch->on_keydown_down([&]() { on_move(direction::down); });
}
}
