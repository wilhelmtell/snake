#include "berry_control.hh"
#include "abstract_factory.hh"

namespace snk {
berry_control::berry_control(abstract_factory const& factory)
: out{factory.make_berry_output()} {}

void berry_control::handle_event(event const& /*e*/) {}

void berry_control::update() {}

void berry_control::draw() {}
}
