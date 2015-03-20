#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

#include "width.hh"
#include "height.hh"

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(width w, height h);

public:
  int w;
  int h;
};
}

#endif
