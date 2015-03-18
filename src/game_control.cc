#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "event.hh"

namespace snk {
game_control::game_control(abstract_factory* factory)
: game_control{factory->make_game_output(), factory} {}

game_control::game_control(std::unique_ptr<game_output> out,
                           abstract_factory* factory)
: out{std::move(out)}
, snake{factory}
, end_game_requested{false} {}

void game_control::handle_event(event const& e) {
  end_game_requested = e.type == event::keydown_esc;
  snake.handle_event(e);
}

void game_control::update() {
  snake.update();
}

void game_control::draw() {
  out->clear(0x00, 0x00, 0x00, 0xff);
  snake.draw();
  out->present();
}

bool game_control::game_over() const { return end_game_requested; }
}
