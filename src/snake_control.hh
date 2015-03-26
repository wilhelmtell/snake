#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"
#include "event_dispatch_fwd.hh"
#include "snake_body_control.hh"
#include "point_fwd.hh"

namespace snk {
struct snake_control {
  snake_control(abstract_factory* factory, event_dispatch* dispatch);
  snake_control(std::unique_ptr<snake_output> out,
                abstract_factory* factory,
                event_dispatch* dispatch);

  void update();
  void draw() const;

  bool dead() const;
  point position() const;

private:
  std::unique_ptr<snake_output> out;
  snake_body_control body;
};
}

#endif
