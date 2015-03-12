#ifndef SNK_TEST_QUIT_GAME_INPUT_HH_
#define SNK_TEST_QUIT_GAME_INPUT_HH_

#include "../src/game_input.hh"
#include "../src/game_control_fwd.hh"

namespace snk {
namespace test {
struct quit_game_input : snk::game_input {
  explicit quit_game_input(snk::game_control* const control);

  void tick() override;

private:
  snk::game_control* control;
};
}
}

#endif
