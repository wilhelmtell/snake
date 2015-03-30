#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

#include "width.hh"
#include "height.hh"
#include "point.hh"

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(point p, width w, height h);

public:
  point p;
  width w;
  height h;
};

bool intersect(rectangle const& a, rectangle const& b);
bool outside(rectangle const& a, rectangle const& b);
point bottom_right(rectangle const& r);
}

#endif
