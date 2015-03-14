#ifndef SNK_RECTANGLE_HH_
#define SNK_RECTANGLE_HH_

namespace snk {
struct rectangle {
  rectangle() = default;
  rectangle(int w, int h);

public:
  int w;
  int h;
};
}

#endif
