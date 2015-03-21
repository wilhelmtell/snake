#ifndef SNK_DIRECTION_HH_
#define SNK_DIRECTION_HH_

namespace snk {
enum class direction { up, right, down, left };

bool are_opposite(direction const& a, direction const& b);
}

#endif
