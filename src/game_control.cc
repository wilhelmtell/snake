#include "game_control.hh"
#include "abstract_factory.hh"
#include "game_output.hh"
#include "game_input.hh"
#include "window_control.hh"

namespace snk {
game_control::game_control(abstract_factory const& factory)
: input{factory.make_game_input()}
, output{factory.make_game_output()}
, w_c{factory} {
  input->controlled_by(this);
}

void game_control::notify_end() { output = nullptr; }

bool game_control::is_on() const { return output != nullptr; }

void game_control::tick() { input->tick(); }
}
