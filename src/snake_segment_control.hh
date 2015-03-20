#ifndef SNK_SNAKE_SEGMENT_CONTROL_HH_
#define SNK_SNAKE_SEGMENT_CONTROL_HH_

#include "rectangle.hh"

namespace snk {
struct snake_segment_control {
  snake_segment_control() = default;
  explicit snake_segment_control(rectangle rect);

public:
  rectangle rect;
};
}

#endif
