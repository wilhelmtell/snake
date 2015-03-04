#ifndef SNK_WINDOW_INPUT_HH_
#define SNK_WINDOW_INPUT_HH_

#include "window_control_fwd.hh"

namespace snk {
struct window_input {
  virtual ~window_input() {}
  virtual void controlled_by(window_control* control) = 0;
  virtual void tick() = 0;
};
}

#endif
