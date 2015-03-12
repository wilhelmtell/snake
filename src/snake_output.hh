#ifndef SNK_SNAKE_OUTPUT_HH_
#define SNK_SNAKE_OUTPUT_HH_

namespace snk {
struct snake_output {
  virtual ~snake_output() {}

  virtual void get_drawable_size(int* w, int* h) = 0;
  virtual void set_colour(int r, int g, int b, int a) = 0;
  virtual void draw_rect(int x, int y, int w, int h) = 0;
};
}

#endif
