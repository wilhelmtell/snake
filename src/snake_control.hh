#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"
#include "event_fwd.hh"
#include "snake_body_control.hh"

namespace snk {
struct snake_control {
  explicit snake_control(abstract_factory* factory);
  snake_control(abstract_factory* factory, std::unique_ptr<snake_output> out);

  void handle_event(event const& e);
  void update();
  void draw();

  bool dead() const;

private:
  std::unique_ptr<snake_output> out;
  snake_body_control body;
};
}

#endif
