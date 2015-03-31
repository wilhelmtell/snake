#include "snake_direction_control.hh"
#include <memory>
#include <utility>
#include "event_dispatch.hh"
#include "abstract_factory.hh"
#include "snake_direction_output.hh"

namespace snk {
snake_direction_control::snake_direction_control(event_dispatch* dispatch,
                                                 abstract_factory* factory)
: snake_direction_control{
    dispatch, factory, factory->make_snake_direction_output()} {}

snake_direction_control::snake_direction_control(
  event_dispatch* /*dispatch*/,
  abstract_factory* /*factory*/,
  std::unique_ptr<snake_direction_output> out)
: out{std::move(out)} {}
}
