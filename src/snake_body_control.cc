#include "snake_body_control.hh"
#include <utility>
#include "abstract_factory.hh"
#include "event.hh"

namespace snk {
snake_body_control::snake_body_control(abstract_factory* factory)
: snake_body_control{std::move(factory), factory->make_snake_body_output()} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out)
: factory{std::move(factory)}, out{std::move(out)} {}

void snake_body_control::handle_event(event const& /*e*/) {}

void snake_body_control::update() {}

void snake_body_control::draw() const {}

bool snake_body_control::dead() const { return false; }
}
