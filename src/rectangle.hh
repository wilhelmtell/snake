#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

#include "width.hh"
#include "height.hh"
#include "position_fwd.hh"

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(width w, height h);
  rectangle(width w, height h, position const& p);

public:
  int w;
  int h;
  int x;
  int y;
};
}

#endif
