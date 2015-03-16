#ifndef SNK_SNAKE_SEGMENT_HH_
#define SNK_SNAKE_SEGMENT_HH_

#include "rectangle.hh"
#include "position.hh"

namespace snk {
struct snake_segment {
  snake_segment() = default;
  snake_segment(position pos, rectangle rect);

public:
  position pos;
  rectangle rect;
};
}

#endif
