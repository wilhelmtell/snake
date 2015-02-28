#ifndef SNK_TEST_QUIT_GAME_VIEW_HH_
#define SNK_TEST_QUIT_GAME_VIEW_HH_

#include "../src/game_view.hh"
#include "../src/game_control_fwd.hh"

namespace snk {
namespace test {
struct quit_game_view : snk::game_view {
  void controlled_by(game_control* const ctrl);
  void tick();

private:
  game_control* ctrl;
};
}
}

#endif
