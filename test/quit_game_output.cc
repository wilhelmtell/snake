#include "quit_game_output.hh"
#include "../src/game_control.hh"

namespace snk {
namespace test {
void quit_game_output::controlled_by(game_control* const control) {
  this->control = control;
}
}
}
