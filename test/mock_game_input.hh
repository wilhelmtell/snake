#ifndef SNK_TEST_MOCK_GAME_INPUT_HH_
#define SNK_TEST_MOCK_GAME_INPUT_HH_

#include "../src/game_input.hh"
#include "game_control.hh"

namespace snk {
namespace test {
struct mock_game_input : snk::game_input {
  void controlled_by(game_control* const control) override;
  void tick() override;

private:
  game_control* control;
};
}
}

#endif
