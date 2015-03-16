#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"
#include "event_fwd.hh"
#include "position.hh"
#include "rectangle.hh"

namespace snk {
struct snake_control {
  explicit snake_control(abstract_factory*);
  explicit snake_control(std::unique_ptr<snake_output> out);
  snake_control(std::unique_ptr<snake_output> out, position pos);
  snake_control(std::unique_ptr<snake_output> out,
                position pos,
                rectangle rect);

  void handle_event(event const& e);
  void update();
  void draw();

  bool dead() const;

private:
  std::unique_ptr<snake_output> out;
  int arrow_key_press;  // none = -1, 0=up, 1=right, 2=down, 3=left
  int direction;  // still = -1, 0=up, 1=right, 2=down, 3=left
  position pos;
  rectangle rect;
  bool expired;
};
}

#endif
