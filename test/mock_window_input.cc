#include "mock_window_input.hh"
#include "../src/window_control.hh"

namespace snk {
namespace test {
mock_window_input::mock_window_input(snk::window_control* const control)
: control{control} {}

void mock_window_input::tick() {}
}
}
