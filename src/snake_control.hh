#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include <chrono>
#include "snake_output.hh"
#include "event_dispatch_fwd.hh"
#include "snake_body_control.hh"
#include "point_fwd.hh"

namespace snk {
struct snake_control {
  snake_control(abstract_factory* factory, event_dispatch* dispatch);
  snake_control(event_dispatch* dispatch,
                abstract_factory* factory,
                std::unique_ptr<snake_output> out);

  void update();
  void draw() const;

  point position() const;

private:
  bool dead() const;
  void on_keydown_return();
  void on_restart();
  void on_berry_eaten(point const& position);

private:
  event_dispatch* dispatch;
  std::unique_ptr<snake_output> out;
  std::chrono::system_clock::time_point last_timestamp;
  double speed;
  snake_body_control body;
};
}

#endif
