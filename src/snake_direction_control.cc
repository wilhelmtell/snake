#include "snake_direction_control.hh"
#include <memory>
#include <utility>
#include "event_dispatch.hh"
#include "abstract_factory.hh"
#include "snake_direction_output.hh"
#include "direction.hh"

namespace snk {
snake_direction_control::snake_direction_control(event_dispatch* dispatch,
                                                 abstract_factory* factory,
                                                 direction move_to)
: snake_direction_control{dispatch,
                          factory,
                          factory->make_snake_direction_output(),
                          std::move(move_to)} {}

snake_direction_control::snake_direction_control(
  event_dispatch* dispatch,
  abstract_factory* /*factory*/,
  std::unique_ptr<snake_direction_output> out,
  direction move_to)
: dispatch{dispatch}
, out{std::move(out)}
, move_requests{move_to}
, move_to{std::move(move_to)}
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
  dispatch->on_restart([&]() { on_restart(); });
}

void snake_direction_control::update() {
  auto const next_move = fetch_next_move();
  move_to = are_opposite(move_to, next_move) ? move_to : next_move;
}

void snake_direction_control::draw() const {}

direction snake_direction_control::to() const { return move_to; }

direction snake_direction_control::fetch_next_move_request() {
  auto const move_requested = move_requests.front();
  move_requests.pop_front();
  return move_requested;
}

direction snake_direction_control::fetch_next_move() {
  return move_requests.empty() ? move_to : fetch_next_move_request();
}

void snake_direction_control::on_move(direction const& to) {
  move_requests.push_back(to);
}

void snake_direction_control::on_game_paused() {
  keydown_left_connection.disconnect();
  keydown_right_connection.disconnect();
  keydown_up_connection.disconnect();
  keydown_down_connection.disconnect();
}

void snake_direction_control::on_game_resumed() {
  keydown_left_connection
    = dispatch->on_keydown_left([&]() { on_move(direction::left); });
  keydown_right_connection
    = dispatch->on_keydown_right([&]() { on_move(direction::right); });
  keydown_up_connection
    = dispatch->on_keydown_up([&]() { on_move(direction::up); });
  keydown_down_connection
    = dispatch->on_keydown_down([&]() { on_move(direction::down); });
}

void snake_direction_control::on_restart() {
  move_requests.assign({direction::right});
  move_to = direction::right;
}
}
