#ifndef SNK_TEST_MOCK_BERRY_OUTPUT_HH_
#define SNK_TEST_MOCK_BERRY_OUTPUT_HH_

#include "../src/berry_output.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
struct mock_berry_output : berry_output {
  explicit mock_berry_output(rectangle bounding_rect);

  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(rectangle const& rect) override;
  rectangle bounds() const override;

private:
  rectangle bounding_rect;
};
}
}

#endif
