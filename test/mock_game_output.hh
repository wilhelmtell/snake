#ifndef SNK_TEST_MOCK_GAME_OUTPUT_HH_
#define SNK_TEST_MOCK_GAME_OUTPUT_HH_

#include "../src/game_output.hh"

namespace snk {
namespace test {
struct mock_game_output : snk::game_output {
  void clear(int r, int g, int b, int a) override;
  void present() override;
};
}
}

#endif
