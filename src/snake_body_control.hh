#ifndef SNK_SNAKE_BODY_CONTROL_HH_
#define SNK_SNAKE_BODY_CONTROL_HH_

#include <memory>
#include <deque>
#include "event_dispatch.hh"
#include "abstract_factory_fwd.hh"
#include "snake_body_output.hh"
#include "snake_direction_control.hh"
#include "snake_segment_control.hh"
#include "direction_fwd.hh"
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

  bool dead() const;
  point head_position() const;

private:
  bool wall_hit() const;
  bool self_hit() const;
  void on_berry_eaten(point const& position);
  void on_restart();

private:
  event_dispatch* dispatch;
  abstract_factory* factory;
  std::unique_ptr<snake_body_output> out;
  snake_direction_control direction_control;
  snake_segments segments;
};
}

#endif
