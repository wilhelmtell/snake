#include "snake_control.hh"
#include "abstract_factory.hh"

namespace snk {
snake_control::snake_control(abstract_factory const& factory)
: out{factory.make_snake_output()} {}

snake_control::snake_control(std::unique_ptr<snake_output> out)
: out{std::move(out)} {}

void snake_control::handle_event(event const& /*e*/) {}

void snake_control::update() {}

void snake_control::draw() {}
}
