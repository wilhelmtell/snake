#ifndef SNK_POINT_TO_STRING_HH_
#define SNK_POINT_TO_STRING_HH_

#include <iosfwd>
#include "../src/point_fwd.hh"

namespace snk {
std::ostream& operator<<(std::ostream& out, point const& pos);
}

#endif
