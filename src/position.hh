#ifndef SNK_POSITION_HH_
#define SNK_POSITION_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct position {
  position() = default;
  position(int x, int y);

public:
  int x;
  int y;
};

bool operator==(position const& lhs, position const& rhs);
bool operator!=(position const& lhs, position const& rhs);

bool outside(position const& p, rectangle const& b);
}

#endif
