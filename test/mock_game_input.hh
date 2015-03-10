#ifndef SNK_TEST_MOCK_GAME_INPUT_HH_
#define SNK_TEST_MOCK_GAME_INPUT_HH_

#include "../src/game_input.hh"
#include "game_control.hh"

namespace snk {
namespace test {
struct mock_game_input : snk::game_input {
  explicit mock_game_input(game_control* const control);

  void tick() override;
};
}
}

#endif
