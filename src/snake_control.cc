#include "snake_control.hh"
#include "abstract_factory.hh"
#include "event_dispatch.hh"

namespace snk {
snake_control::snake_control(abstract_factory* factory,
                             event_dispatch* dispatch)
: snake_control{factory->make_snake_output(), factory, dispatch} {}

snake_control::snake_control(std::unique_ptr<snake_output> out,
                             abstract_factory* factory,
                             event_dispatch* dispatch)
: out{std::move(out)}, body{std::move(factory), dispatch} {
}

void snake_control::update() {
  if(dead()) return;
  body.update();
}

void snake_control::draw() const { body.draw(); }

bool snake_control::dead() const { return body.dead(); }

point snake_control::position() const { return body.head_position(); }
}
