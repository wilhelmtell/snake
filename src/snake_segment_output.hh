#ifndef SNK_SNAKE_SEGMENT_OUTPUT_HH_
#define SNK_SNAKE_SEGMENT_OUTPUT_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct snake_segment_output {
  virtual ~snake_segment_output() {}

  virtual void set_colour(int r, int g, int b, int a) = 0;
  virtual void draw_rect(rectangle const& rect) = 0;
};
}

#endif
