#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event.hh"

namespace snk {
snake_control::snake_control(abstract_factory* factory)
: snake_control{factory, factory->make_snake_output()} {}

snake_control::snake_control(abstract_factory* factory,
                             std::unique_ptr<snake_output> out)
: out{std::move(out)}, body{std::move(factory)} {}

void snake_control::handle_event(event const& e) { body.handle_event(e); }

void snake_control::update() {
  if(dead()) return;
  body.update();
}

void snake_control::draw() { body.draw(); }

void snake_control::grow() { body.grow(); }

bool snake_control::dead() const { return body.dead(); }

point snake_control::position() const { return body.head_position(); }
}
