#ifndef SNK_SNAKE_OUTPUT_HH_
#define SNK_SNAKE_OUTPUT_HH_

namespace snk {
struct snake_output {
  virtual ~snake_output() {}

  virtual void position(int x, int y) = 0;
};
}

#endif
