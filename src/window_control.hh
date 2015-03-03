#ifndef SNK_WINDOW_CONTROL_HH_
#define SNK_WINDOW_CONTROL_HH_

#include "window_output_fwd.hh"
#include "window_control_fwd.hh"

namespace snk {
struct window_control {
  explicit window_control(window_output* output);
  void controlled_by(window_control* control);

private:
  window_output* output;
};
}

#endif
