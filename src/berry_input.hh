#ifndef SNK_BERRY_INPUT_HH_
#define SNK_BERRY_INPUT_HH_

#include "berry_control_fwd.hh"

namespace snk {
struct berry_input {
  virtual ~berry_input() {}
  virtual void controlled_by(berry_control* control) = 0;
  virtual void tick() = 0;
};
}

#endif
