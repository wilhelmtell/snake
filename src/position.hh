#ifndef SNK_POSITION_HH_
#define SNK_POSITION_HH_

namespace snk {
struct position {
  position() = default;
  position(int x, int y);

public:
  int x;
  int y;
};
}

#endif
