#ifndef SNK_BERRY_CONTROL_HH_
#define SNK_BERRY_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include "event.hh"

namespace snk {
struct berry_control {
  explicit berry_control(abstract_factory const&);

  void handle_event(event const& e);
  void update();
  void draw();
};
}

#endif
