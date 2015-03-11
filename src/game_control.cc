#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "window_control.hh"

namespace snk {
game_control::game_control(abstract_factory const& factory)
: output{factory.make_game_output()}, w_c{factory} {}

game_control::game_control(std::unique_ptr<game_output> output,
                           abstract_factory const& factory)
: output{std::move(output)}, w_c{factory} {}

void game_control::handle_event(event const& /*e*/) {}
}
