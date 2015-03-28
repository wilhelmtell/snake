#ifndef SNK_GAME_OUTPUT_HH_
#define SNK_GAME_OUTPUT_HH_

#include "rectangle_fwd.hh"

namespace snk {
struct game_output {
  virtual ~game_output() {}

  virtual void draw_score(int score,
                          unsigned char r,
                          unsigned char g,
                          unsigned char b,
                          unsigned char a) = 0;
  virtual void clear(int r, int g, int b, int a) = 0;
  virtual void present() = 0;
  virtual rectangle bounds() const = 0;
};
}

#endif
