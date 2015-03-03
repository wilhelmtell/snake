#include "quit_game_input.hh"
#include "../src/game_control.hh"

namespace snk {
namespace test {
void quit_game_input::controlled_by(snk::game_control* control) {
  this->control = control;
}

void quit_game_input::tick() { control->notify_end(); }
}
}
