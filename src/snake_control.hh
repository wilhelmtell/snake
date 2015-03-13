#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"
#include "event_fwd.hh"

namespace snk {
struct snake_control {
  explicit snake_control(abstract_factory const&);
  explicit snake_control(std::unique_ptr<snake_output> out);

  void handle_event(event const& e);
  void update();
  void draw();

private:
  std::unique_ptr<snake_output> out;
  int direction;  // 0=up, 1=right, 2=down, 3=left
  int x, y;
  int w, h;
};
}

#endif
