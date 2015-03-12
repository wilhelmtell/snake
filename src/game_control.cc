#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "event.hh"

namespace snk {
game_control::game_control(abstract_factory const& factory)
: output{factory.make_game_output()}, snake{factory} {}

void game_control::handle_event(event const& e) {
  snake.handle_event(e);
}

void game_control::update() {
  snake.update();
}

void game_control::draw() {
  snake.draw();
}
}
