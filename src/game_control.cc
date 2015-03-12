#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"

namespace snk {
game_control::game_control(abstract_factory const& factory)
: output{factory.make_game_output()} {}

void game_control::handle_event(event const& /*e*/) {}

void game_control::update() {}

void game_control::draw() {}
}
