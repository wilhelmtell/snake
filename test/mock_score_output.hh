#ifndef SNK_TEST_MOCK_SCORE_OUTPUT_HH_
#define SNK_TEST_MOCK_SCORE_OUTPUT_HH_

#include "../src/score_output.hh"
#include <functional>
#include <string>
#include "../src/rectangle.hh"
#include "../src/width.hh"
#include "../src/height.hh"

namespace snk {
namespace test {
struct mock_score_output : snk::score_output {
  void draw_text(std::string const& text,
                 unsigned char r,
                 unsigned char g,
                 unsigned char b,
                 unsigned char a,
                 std::function<rectangle(width const&, height const&)>
                   bounding_box) override;
  rectangle bounds() const override;
};
}
}

#endif
