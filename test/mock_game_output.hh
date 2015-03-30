#ifndef SNK_TEST_MOCK_GAME_OUTPUT_HH_
#define SNK_TEST_MOCK_GAME_OUTPUT_HH_

#include "../src/game_output.hh"
#include "../src/rectangle.hh"
#include "../src/width.hh"
#include "../src/height.hh"
#include <string>
#include <functional>

namespace snk {
namespace test {
struct mock_game_output : snk::game_output {
  explicit mock_game_output(rectangle bounds);

  void draw_text(std::string const& text,
                 unsigned char r,
                 unsigned char g,
                 unsigned char b,
                 unsigned char a,
                 std::function<rectangle(width const&, height const&)>
                   bounding_box) override;
  void clear(int r, int g, int b, int a) override;
  void present() override;
  rectangle bounds() const override;

private:
  rectangle bounding_rect;
};
}
}

#endif
