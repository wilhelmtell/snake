#ifndef SNK_SNAKE_SEGMENT_HH_
#define SNK_SNAKE_SEGMENT_HH_

#include "rectangle.hh"

namespace snk {
struct snake_segment {
  snake_segment() = default;
  explicit snake_segment(rectangle rect);

public:
  rectangle rect;
};
}

#endif
