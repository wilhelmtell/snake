#include "game_control.hh"
#include <memory>
#include "abstract_factory.hh"
#include "game_output.hh"
#include "event.hh"
#include "width.hh"
#include "height.hh"
#include <random>

namespace {
snk::width const default_berry_width{10};
snk::height const default_berry_height{10};
std::random_device rd;
std::mt19937 gen{rd()};
}

namespace {
snk::point random_position(snk::rectangle const& bounds,
                           int xgranularity,
                           int ygranularity) {
  std::uniform_int_distribution<> xdist{bounds.p.x, bounds.w};
  std::uniform_int_distribution<> ydist{bounds.p.y, bounds.h};
  auto const x = xdist(gen);
  auto const y = ydist(gen);
  return snk::point{x - x % xgranularity, y - y % ygranularity};
}
}

namespace snk {
game_control::game_control(abstract_factory* factory)
: game_control{factory->make_game_output(), factory} {}

game_control::game_control(std::unique_ptr<game_output> out,
                           abstract_factory* factory)
: factory{factory}
, out{std::move(out)}
, berry{factory,
        random_position(this->out->bounds(),
                        default_berry_width.get(),
                        default_berry_height.get()),
        default_berry_width,
        default_berry_height}
, snake{factory}
, end_game_requested{false} {}

void game_control::handle_event(event const& e) {
  if(e == event::keydown_esc) end_game_requested = true;
  snake.handle_event(e);
  berry.handle_event(e);
}

void game_control::update() {
  berry.update();
  snake.update();
  if(snake.position() == berry.position()) {
    snake.grow();
    berry = berry_control{factory,
                          random_position(this->out->bounds(),
                                          default_berry_width.get(),
                                          default_berry_height.get()),
                          default_berry_width,
                          default_berry_height};
  }
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
