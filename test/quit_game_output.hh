#ifndef SNK_TEST_QUIT_GAME_OUTPUT_HH_
#define SNK_TEST_QUIT_GAME_OUTPUT_HH_

#include "../src/game_output.hh"
#include "../src/game_control_fwd.hh"

namespace snk {
namespace test {
struct quit_game_output : snk::game_output {
  void controlled_by(game_control* const control);

private:
  game_control* control;
};
}
}

#endif
