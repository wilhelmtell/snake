#include "mock_snake_input.hh"

namespace snk {
namespace test {
mock_snake_input::mock_snake_input(snake_control* const control)
: control{control} {}

void mock_snake_input::tick() {}
}
}
