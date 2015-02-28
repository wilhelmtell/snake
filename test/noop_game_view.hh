#ifndef SNK_TEST_NOOP_GAME_VIEW_HH_
#define SNK_TEST_NOOP_GAME_VIEW_HH_

#include "../src/game_view.hh"

namespace snk {
namespace test {
struct noop_game_view : snk::game_view {
  void control(game_control* const);
  void tick();
};
}
}

#endif
