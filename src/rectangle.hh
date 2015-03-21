#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(position p, width w, height h);

public:
  position p;
  int w;
  int h;
};

bool intersect(rectangle const& a, rectangle const& b);
}

#endif
