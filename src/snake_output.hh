#ifndef SNK_SNAKE_OUTPUT_HH_
#define SNK_SNAKE_OUTPUT_HH_

#include "position_fwd.hh"
#include "rectangle_fwd.hh"

namespace snk {
struct snake_output {
  virtual ~snake_output() {}

  virtual rectangle get_drawable_size() = 0;
  virtual void set_colour(int r, int g, int b, int a) = 0;
  virtual void draw_rect(position const& pos, rectangle const& rect) = 0;
};
}

#endif
