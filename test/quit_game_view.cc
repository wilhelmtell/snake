#include "quit_game_view.hh"
#include "../src/game_control.hh"

namespace snk {
namespace test {
void quit_game_view::controlled_by(game_control* const control) {
  this->control = control;
}

void quit_game_view::tick() {
  control->notify_end();
}
}
}
