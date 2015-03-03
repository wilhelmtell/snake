#ifndef SNK_TEST_NOOP_GAME_INPUT_HH_
#define SNK_TEST_NOOP_GAME_INPUT_HH_

#include "../src/game_input.hh"

namespace snk {
namespace test {
struct noop_game_input : snk::game_input {
  void tick();
};
}
}

#endif
