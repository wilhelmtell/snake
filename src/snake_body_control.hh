#ifndef SNK_SNAKE_BODY_CONTROL_HH_
#define SNK_SNAKE_BODY_CONTROL_HH_

#include <memory>
#include <deque>
#include "event_dispatch_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "snake_body_output.hh"
#include "snake_segment_control.hh"
#include "direction.hh"
#include "point_fwd.hh"

namespace snk {
struct snake_body_control {
  using snake_segments = std::deque<snake_segment_control>;

  snake_body_control(abstract_factory* factory,
                              event_dispatch* dispatch);
  snake_body_control(abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out,
                     event_dispatch* dispatch);
  snake_body_control(abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out,
                     event_dispatch* dispatch,
                     direction move_request);

  void update();
  void draw() const;

  bool dead() const;
  point head_position() const;

private:
  bool wall_hit() const;
  bool self_hit() const;
  void on_berry_eaten(point const& position);

private:
  abstract_factory* factory;
  std::unique_ptr<snake_body_output> out;
  event_dispatch* dispatch;
  direction move_requested;
  direction move_to;
  snake_segments segments;
};
}

#endif
