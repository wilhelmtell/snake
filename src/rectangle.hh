#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

#include "width.hh"
#include "height.hh"
#include "position_fwd.hh"

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(width w, height h);
  rectangle(position const& p, width w, height h);

public:
  int x;
  int y;
  int w;
  int h;
};
}

#endif
