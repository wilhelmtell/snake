#ifndef SNK_SNAKE_VIEW_HH_
#define SNK_SNAKE_VIEW_HH_

namespace snk {
struct snake_view {
  virtual ~snake_view() {}

  virtual void position(int x, int y) = 0;
};
}

#endif
