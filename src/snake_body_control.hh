#ifndef SNK_SNAKE_BODY_CONTROL_HH_
#define SNK_SNAKE_BODY_CONTROL_HH_

#include <memory>
#include <deque>
#include "event_dispatch.hh"
#include "abstract_factory_fwd.hh"
#include "snake_body_output.hh"
#include "snake_segment_control.hh"
#include "direction.hh"
#include "point_fwd.hh"

namespace snk {
struct snake_body_control {
  using snake_segments = std::deque<snake_segment_control>;

  snake_body_control(event_dispatch* dispatch, abstract_factory* factory);
  snake_body_control(event_dispatch* dispatch,
                     abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out);
  snake_body_control(event_dispatch* dispatch,
                     abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out,
                     direction move_request);

  void update();
  void draw() const;

  void restart();

  bool dead() const;
  point head_position() const;

private:
  direction fetch_next_move_request();
  direction fetch_next_move();
  bool wall_hit() const;
  bool self_hit() const;
  void on_berry_eaten(point const& position);
  void on_move(direction const& to);
  void on_game_paused();
  void on_game_resumed();

private:
  event_dispatch* dispatch;
  abstract_factory* factory;
  std::unique_ptr<snake_body_output> out;
  std::deque<direction> move_requests;
  direction move_to;
  snake_segments segments;
  event_dispatch::connection keydown_left_connection;
  event_dispatch::connection keydown_right_connection;
  event_dispatch::connection keydown_up_connection;
  event_dispatch::connection keydown_down_connection;
};
}

#endif
