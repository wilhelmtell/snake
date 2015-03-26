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
: factory{factory}
, out{std::move(out)}
, dispatch{dispatch}
, berry{make_randomly_positioned_berry(
    factory, dispatch, default_berry_width, default_berry_height)}
, snake{factory, dispatch}
, end_game_requested{false}
, game_paused{false} {
  dispatch->on_keydown_esc([&]() { on_keydown_esc(); });
  dispatch->on_keydown_p([&]() { on_keydown_p(); });
  dispatch->on_berry_eaten([&](auto const& p) { on_berry_eaten(p); });
  dispatch->on_pause_game([&]() { on_pause_game(); });
  dispatch->on_resume_game([&]() { on_resume_game(); });
}

void game_control::update() {
  if(game_paused) return;
  if(snake.position() == berry.position())
    dispatch->berry_eaten(snake.position());
  berry.update();
  snake.update();
}

void game_control::draw() const {
  out->clear(0x00, 0x00, 0x00, 0xff);
  berry.draw();
  snake.draw();
  out->present();
}

bool game_control::game_over() const {
  return end_game_requested || snake.dead();
}

void game_control::on_keydown_esc() { end_game_requested = true; }

void game_control::on_keydown_p() {
  if(game_paused)
    dispatch->resume_game();
  else
    dispatch->pause_game();
}

void game_control::on_berry_eaten(point const& /*position*/) {
  berry = make_randomly_positioned_berry(
    factory, dispatch, default_berry_width, default_berry_height);
}

void game_control::on_pause_game() { game_paused = true; }

void game_control::on_resume_game() { game_paused = false; }
}
