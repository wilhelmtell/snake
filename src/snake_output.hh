#ifndef SNK_SNAKE_OUTPUT_HH_
#define SNK_SNAKE_OUTPUT_HH_

namespace snk {
struct snake_output {
  virtual ~snake_output() {}

  virtual void draw_rect(int x, int y, int w, int h) = 0;
};
}

#endif
