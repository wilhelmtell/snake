#include "quit_game_input.hh"
#include "../src/game_control.hh"

namespace snk {
namespace test {
quit_game_input::quit_game_input(snk::game_control* const control)
: control{control} {}

void quit_game_input::tick() { control->notify_end(); }
}
}
