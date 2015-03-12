#ifndef SNK_BERRY_CONTROL_HH_
#define SNK_BERRY_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "berry_output.hh"
#include "event.hh"

namespace snk {
struct berry_control {
  explicit berry_control(abstract_factory const&);

  void handle_event(event const& e);
  void update();
  void draw();

private:
  std::unique_ptr<berry_output> out;
};
}

#endif
