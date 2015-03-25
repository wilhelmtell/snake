#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "event.hh"
#include "event_dispatch.hh"
#include "width.hh"
#include "height.hh"

namespace {
snk::width const default_berry_width{10};
snk::height const default_berry_height{10};
}

namespace snk {
game_control::game_control(abstract_factory* factory, event_dispatch* dispatch)
: game_control{factory->make_game_output(), factory, dispatch} {}

game_control::game_control(std::unique_ptr<game_output> out,
                           abstract_factory* factory,
                           event_dispatch* dispatch)
: out{std::move(out)}
, dispatch{dispatch}
, berry{make_randomly_positioned_berry(
    factory, dispatch, default_berry_width, default_berry_height)}
, snake{factory, dispatch}
, end_game_requested{false} {
  dispatch->on_keydown_esc([&]() { end_game_requested = true; });
}

void game_control::update() {
  if(snake.position() == berry.position())
    dispatch->berry_eaten(snake.position());
  berry.update();
  snake.update();
}

void game_control::draw() {
  out->clear(0x00, 0x00, 0x00, 0xff);
  berry.draw();
  snake.draw();
  out->present();
}

bool game_control::game_over() const {
  return end_game_requested || snake.dead();
}
}
