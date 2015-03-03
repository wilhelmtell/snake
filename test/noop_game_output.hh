#ifndef SNK_TEST_NOOP_GAME_OUTPUT_HH_
#define SNK_TEST_NOOP_GAME_OUTPUT_HH_

#include "../src/game_output.hh"

namespace snk {
namespace test {
struct noop_game_output : snk::game_output {
  void controlled_by(game_control* const);
  void tick();
};
}
}

#endif
