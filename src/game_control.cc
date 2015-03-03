#include "game_control.hh"
#include "game_output.hh"
#include "game_input.hh"
#include "window_control.hh"

namespace snk {
game_control::game_control(game_input* input,
                           game_output* output,
                           window_output* w_o)
: input{input}, output{output}, w_c{w_o} {}

void game_control::notify_end() { output = nullptr; }

bool game_control::is_on() const { return output != nullptr; }

void game_control::tick() { input->tick(); }
}
