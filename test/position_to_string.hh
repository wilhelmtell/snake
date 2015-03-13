#ifndef SNK_POSITION_TO_STRING_HH_
#define SNK_POSITION_TO_STRING_HH_

#include <iosfwd>
#include "../src/position_fwd.hh"

namespace snk {
std::ostream& operator<<(std::ostream& out, position const& pos);
}

#endif
