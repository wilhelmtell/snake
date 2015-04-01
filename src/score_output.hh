#ifndef SNK_SCORE_OUTPUT_HH_
#define SNK_SCORE_OUTPUT_HH_

#include <functional>
#include <string>
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
struct score_output {
  virtual ~score_output() {}

  virtual void draw_text(
    std::string const& text,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a,
    std::function<rectangle(width const&, height const&)> bounding_box) = 0;
  virtual rectangle bounds() const = 0;
};
}

#endif
