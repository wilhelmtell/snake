#ifndef SNK_SNAKE_INPUT_HH_
#define SNK_SNAKE_INPUT_HH_

#include "snake_control_fwd.hh"

namespace snk {
struct snake_input {
  virtual ~snake_input(){};
  virtual void tick() = 0;
};
}

#endif
