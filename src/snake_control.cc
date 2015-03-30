#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event_dispatch.hh"
#include <chrono>

namespace snk {
snake_control::snake_control(abstract_factory* factory,
                             event_dispatch* dispatch)
: snake_control{dispatch, factory, factory->make_snake_output()} {}

snake_control::snake_control(event_dispatch* dispatch,
                             abstract_factory* factory,
                             std::unique_ptr<snake_output> out)
: out{std::move(out)}
, last_timestamp{std::chrono::system_clock::now()}
, speed{10}
, body{dispatch, std::move(factory)} {
  dispatch->on_keydown_return([&]() { on_keydown_return(); });
  dispatch->on_berry_eaten([&](point const& p) { on_berry_eaten(p); });
}

void snake_control::update() {
  if(dead()) return;
  auto const now = std::chrono::system_clock::now();
  auto const period_denominator = std::chrono::system_clock::period::den;
  if((now - last_timestamp).count() < period_denominator / speed) return;
  last_timestamp = now;
  body.update();
}

void snake_control::draw() const { body.draw(); }

bool snake_control::dead() const { return body.dead(); }

void snake_control::restart() {
  body.restart();
  speed = 10;
}

point snake_control::position() const { return body.head_position(); }

void snake_control::on_keydown_return() {
  if(dead()) restart();
}

void snake_control::on_berry_eaten(point const& /*position*/) {
  speed += 0.25;
}
}
