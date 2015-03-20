#ifndef SNK_SNAKE_BODY_CONTROL_HH_
#define SNK_SNAKE_BODY_CONTROL_HH_

#include <memory>
#include "event_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "snake_body_output.hh"

namespace snk {
struct snake_body_control {
  explicit snake_body_control(abstract_factory* factory);
  snake_body_control(abstract_factory* factory,
                     std::unique_ptr<snake_body_output> out);

  void handle_event(event const& e);
  void update();
  void draw() const;

  bool dead() const;

private:
  abstract_factory* factory;
  std::unique_ptr<snake_body_output> out;
};
}

#endif
