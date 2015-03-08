#include "mock_game_input.hh"

namespace snk {
namespace test {
mock_game_input::mock_game_input(game_control* const control)
: control{control} {}

void mock_game_input::tick() {}
}
}
