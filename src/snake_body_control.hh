#ifndef SNK_SNAKE_BODY_CONTROL_HH_
#define SNK_SNAKE_BODY_CONTROL_HH_

#include <memory>
#include <deque>
#include "event_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "snake_body_output.hh"
#include "snake_segment_control.hh"
#include "direction.hh"

namespace snk {
struct snake_body_control {
  using snake_segments = std::deque<snake_segment_control>;

  explicit snake_body_control(abstract_factory* factory);
  snake_body_control(abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out);
  snake_body_control(abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out,
                     direction move_request);

  void handle_event(event const& e);
  void update();
  void draw() const;

  bool dead() const;

private:
  abstract_factory* factory;
  std::unique_ptr<snake_body_output> out;
  direction move_requested;
  direction move_to;
  snake_segments segments;
  bool grow;
};
}

#endif
