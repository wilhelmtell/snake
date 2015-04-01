#ifndef SNK_SNAKE_DIRECTION_CONTROL_HH_
#define SNK_SNAKE_DIRECTION_CONTROL_HH_

#include <memory>
#include <deque>
#include "event_dispatch.hh"
#include "abstract_factory_fwd.hh"
#include "snake_direction_output.hh"
#include "direction.hh"

namespace snk {
struct snake_direction_control {
  snake_direction_control(event_dispatch* dispatch,
                          abstract_factory* factory,
                          direction move_to);
  snake_direction_control(event_dispatch* dispatch,
                          abstract_factory* factory,
                          std::unique_ptr<snake_direction_output> out,
                          direction move_to);

  void update();
  void draw() const;

  direction to() const;

private:
  void restart();
  direction fetch_next_move_request();
  direction fetch_next_move();
  void on_move(direction const& to);
  void on_game_paused();
  void on_game_resumed();

private:
  event_dispatch* dispatch;
  std::unique_ptr<snake_direction_output> out;
  std::deque<direction> move_requests;
  direction move_to;
  event_dispatch::connection keydown_left_connection;
  event_dispatch::connection keydown_right_connection;
  event_dispatch::connection keydown_up_connection;
  event_dispatch::connection keydown_down_connection;
};
}

#endif
