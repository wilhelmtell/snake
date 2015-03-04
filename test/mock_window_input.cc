#include "mock_window_input.hh"
#include "../src/window_control.hh"

namespace snk {
namespace test {
void mock_window_input::controlled_by(snk::window_control* control) {
  this->control = control;
}

void mock_window_input::tick() {}
}
}
