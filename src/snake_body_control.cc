#include "snake_body_control.hh"
#include <utility>
#include "abstract_factory.hh"
#include "event.hh"
#include "snake_segment_control.hh"

namespace snk {
snake_body_control::snake_body_control(abstract_factory* factory)
: snake_body_control{std::move(factory), factory->make_snake_body_output()} {}

snake_body_control::snake_body_control(abstract_factory* factory,
                                       std::unique_ptr<snake_body_output> out)
: factory{std::move(factory)}, out{std::move(out)}, segments{} {
  segments.emplace_back(this->factory);
}

void snake_body_control::handle_event(event const& e) {
  for(auto& segment : segments) segment.handle_event(e);
}

void snake_body_control::update() {
  for(auto& segment : segments) segment.update();
}

void snake_body_control::draw() const {
  for(auto const& segment : segments) segment.draw();
}

bool snake_body_control::dead() const {
  return segments.front().intersect(out->bounds());
}
}
