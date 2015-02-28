#include "quit_game_view.hh"
#include "../src/game_control.hh"

namespace snk {
namespace test {
void quit_game_view::controlled_by(game_control* const ctrl) {
  this->ctrl = ctrl;
}

void quit_game_view::tick() {
  ctrl->notify_end();
}
}
}
