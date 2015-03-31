#ifndef SNK_SNAKE_DIRECTION_CONTROL_HH_
#define SNK_SNAKE_DIRECTION_CONTROL_HH_

#include <memory>
#include "event_dispatch_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "snake_direction_output.hh"

namespace snk {
struct snake_direction_control {
  snake_direction_control(event_dispatch* dispatch, abstract_factory* factory);
  snake_direction_control(event_dispatch* dispatch,
                          abstract_factory* factory,
                          std::unique_ptr<snake_direction_output> out);

private:
  std::unique_ptr<snake_direction_output> out;
};
}

#endif
