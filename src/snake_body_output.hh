#ifndef SNK_SNAKE_BODY_OUTPUT_HH_
#define SNK_SNAKE_BODY_OUTPUT_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct snake_body_output {
  virtual ~snake_body_output() {}

  virtual rectangle get_drawable_size() const = 0;
};
}

#endif
