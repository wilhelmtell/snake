#include "berry_control.hh"
#include <utility>
#include "abstract_factory.hh"

namespace snk {
berry_control::berry_control(abstract_factory* factory,
                             point position,
                             width berry_width,
                             height berry_height)
: out{factory->make_berry_output()}
, rect{std::move(position), std::move(berry_width), std::move(berry_height)} {}

void berry_control::handle_event(event const& /*e*/) {}

void berry_control::update() {}

void berry_control::draw() {
  out->set_colour(0x70, 0x20, 0x00, 0xff);
  out->draw_rect(rect);
}

point berry_control::position() const { return rect.p; }
}
