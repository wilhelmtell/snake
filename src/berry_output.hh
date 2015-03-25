#ifndef SNK_BERRY_OUTPUT_HH_
#define SNK_BERRY_OUTPUT_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct berry_output {
  virtual ~berry_output() {}

  virtual void set_colour(int r, int g, int b, int a) = 0;
  virtual void draw_rect(rectangle const& rect) = 0;
  virtual rectangle bounds() const = 0;
};
}

#endif
