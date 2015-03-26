#include "berry_control.hh"
#include <utility>
#include <random>
#include "abstract_factory.hh"
#include "event_dispatch.hh"
#include "point.hh"
#include "rectangle.hh"

namespace {
std::random_device rd;
std::mt19937 gen{rd()};

snk::point random_position(snk::rectangle const& bounds,
                           int xgranularity,
                           int ygranularity) {
  std::uniform_int_distribution<> xdist{bounds.p.x, bounds.w};
  std::uniform_int_distribution<> ydist{bounds.p.y, bounds.h};
  auto const x = xdist(gen);
  auto const y = ydist(gen);
  return snk::point{x - x % xgranularity, y - y % ygranularity};
}

snk::rectangle randomly_positioned_rectangle(snk::rectangle const& bounds,
                                             snk::width berry_width,
                                             snk::height berry_height) {
  return snk::rectangle{
    random_position(bounds, berry_width.get(), berry_height.get()),
    berry_width,
    berry_height};
}
}

namespace snk {
berry_control::berry_control(abstract_factory* factory,
                             event_dispatch* dispatch,
                             point position,
                             width berry_width,
                             height berry_height)
: out{factory->make_berry_output()}
, rect{std::move(position), std::move(berry_width), std::move(berry_height)} {
  dispatch->berry_spawned(rect.p);
}

void berry_control::update() {}

void berry_control::draw() const {
  out->set_colour(0x70, 0x20, 0x00, 0xff);
  out->draw_rect(rect);
}

point berry_control::position() const { return rect.p; }

berry_control make_randomly_positioned_berry(abstract_factory* factory,
                                             event_dispatch* dispatch,
                                             width berry_width,
                                             height berry_height) {
  auto out = factory->make_berry_output();
  auto const rect
    = randomly_positioned_rectangle(out->bounds(), berry_width, berry_height);
  return berry_control{
    factory, dispatch, rect.p, width{rect.w}, height{rect.h}};
}
}
