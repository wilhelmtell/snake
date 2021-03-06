#include "snake_segment_control.hh"
#include <memory>
#include <utility>
#include "abstract_factory.hh"
#include "snake_segment_output.hh"
#include "event_dispatch.hh"
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"
#include "point.hh"
#include "direction.hh"

namespace snk {
snake_segment_control::snake_segment_control(event_dispatch* dispatch,
                                             abstract_factory* factory,
                                             point position,
                                             width segment_width,
                                             height segment_height)
: snake_segment_control{dispatch,
                        factory,
                        factory->make_snake_segment_output(),
                        std::move(position),
                        std::move(segment_width),
                        std::move(segment_height)} {}

snake_segment_control::snake_segment_control(
  event_dispatch* /*dispatch*/,
  abstract_factory* /*factory*/,
  std::unique_ptr<snake_segment_output> out,
  point position,
  width segment_width,
  height segment_height)
: out{std::move(out)}
, rect{
    std::move(position), std::move(segment_width), std::move(segment_height)} {
}

void snake_segment_control::update() {}

void snake_segment_control::draw() const {
  out->set_colour(0x7f, 0x7f, 0x7f, 0xff);
  out->draw_rect(rect);
}

point snake_segment_control::position() const { return rect.p; }

bool snake_segment_control::outside(rectangle const& bounds) const {
  return snk::outside(rect, bounds);
}

bool snake_segment_control::hit(snake_segment_control const& seg) const {
  return rect.p == seg.rect.p || bottom_right(rect) == bottom_right(seg.rect);
}
}
