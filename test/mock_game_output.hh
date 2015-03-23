#ifndef SNK_TEST_MOCK_GAME_OUTPUT_HH_
#define SNK_TEST_MOCK_GAME_OUTPUT_HH_

#include "../src/game_output.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
struct mock_game_output : snk::game_output {
  explicit mock_game_output(rectangle bounds);

  void clear(int r, int g, int b, int a) override;
  void present() override;
  rectangle bounds() const override;

private:
  rectangle bounding_rect;
};
}
}

#endif
