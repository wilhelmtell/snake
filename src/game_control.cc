#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "event_dispatch.hh"
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"
#include <boost/lexical_cast.hpp>

namespace {
snk::width const default_berry_width{10};
snk::height const default_berry_height{10};
}

namespace snk {
game_control::game_control(event_dispatch* dispatch, abstract_factory* factory)
: game_control{dispatch, factory, factory->make_game_output()} {}

game_control::game_control(event_dispatch* dispatch,
                           abstract_factory* factory,
                           std::unique_ptr<game_output> out)
: dispatch{dispatch}
, factory{factory}
, out{std::move(out)}
, berry{make_randomly_positioned_berry(
    factory, dispatch, default_berry_width, default_berry_height)}
, snake{factory, dispatch}
, game_paused{false}
, score{0} {
  dispatch->on_keydown_esc([&]() { on_keydown_esc(); });
  dispatch->on_keydown_p([&]() { on_keydown_p(); });
  dispatch->on_berry_eaten([&](auto const& p) { on_berry_eaten(p); });
  dispatch->on_toggle_pause([&]() { on_toggle_pause(); });
  dispatch->on_restart([&]() { on_restart(); });
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
  out->draw_text(boost::lexical_cast<std::string>(score),
                 0x70,
                 0x90,
                 0x00,
                 0xff,
                 [&](width const& w, height const& h) {
    return rectangle{point{10, out->bounds().h - h - 10}, w, h};
  });
  out->present();
}

void game_control::on_keydown_esc() { dispatch->quit(); }

void game_control::on_keydown_p() { dispatch->toggle_pause(); }

void game_control::on_berry_eaten(point const& /*position*/) {
  ++score;
  berry = make_randomly_positioned_berry(
    factory, dispatch, default_berry_width, default_berry_height);
}

void game_control::on_toggle_pause() {
  if((game_paused = !game_paused))
    dispatch->game_paused();
  else
    dispatch->game_resumed();
}

void game_control::on_restart() { score = 0; }
}
