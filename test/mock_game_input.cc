#include "mock_game_input.hh"

namespace snk {
namespace test {
void mock_game_input::tick() {}

void mock_game_input::controlled_by(game_control* const control) {
  this->control = control;
}
}
}
