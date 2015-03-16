#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"
#include "event_fwd.hh"
#include "snake_segment.hh"
#include "direction.hh"

namespace snk {
struct snake_control {
  explicit snake_control(abstract_factory*);
  explicit snake_control(std::unique_ptr<snake_output> out);
  snake_control(std::unique_ptr<snake_output> out, snake_segment seg);

  void handle_event(event const& e);
  void update();
  void draw();

  bool dead() const;

private:
  std::unique_ptr<snake_output> out;
  direction move_requested;
  direction next_move;
  snake_segment seg;
  bool expired;
};
}

#endif
