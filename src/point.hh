#ifndef SNK_POINT_HH_
#define SNK_POINT_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct point {
  point() = default;
  point(int x, int y);

public:
  int x;
  int y;
};

bool operator==(point const& lhs, point const& rhs);
bool operator!=(point const& lhs, point const& rhs);

bool outside(point const& p, rectangle const& b);
}

#endif
