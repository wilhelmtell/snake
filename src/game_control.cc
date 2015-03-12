#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "game_input.hh"
#include "window_control.hh"

namespace snk {
game_control::game_control(abstract_factory const& factory)
: input{factory.make_game_input(this)}
, output{factory.make_game_output()}
, w_c{factory} {}

game_control::game_control(std::unique_ptr<game_input> input,
                           std::unique_ptr<game_output> output,
                           abstract_factory const& factory)
: input{std::move(input)}, output{std::move(output)}, w_c{factory} {}

void game_control::notify_end() { output = nullptr; }

bool game_control::quit_requested() const { return output == nullptr; }

void game_control::tick() { input->tick(); }
}
