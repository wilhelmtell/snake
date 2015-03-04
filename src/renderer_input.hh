#ifndef SNK_RENDERER_INPUT_HH_
#define SNK_RENDERER_INPUT_HH_

#include "renderer_control_fwd.hh"

namespace snk {
struct renderer_input {
  virtual ~renderer_input() {}
  virtual controlled_by(renderer_control* control) = 0;
  virtual input() = 0;
};
}

#endif
