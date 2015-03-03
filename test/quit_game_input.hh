#ifndef SNK_QUIT_GAME_INPUT_HH_
#define SNK_QUIT_GAME_INPUT_HH_

#include "../src/game_input.hh"
#include "../src/game_control_fwd.hh"

namespace snk {
namespace test {
struct quit_game_input : snk::game_input {
  void controlled_by(snk::game_control* control);
  void tick();

private:
  snk::game_control* control;
};
}
}

#endif
