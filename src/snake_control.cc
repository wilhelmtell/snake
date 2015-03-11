#include "snake_control.hh"
#include "abstract_factory.hh"

namespace snk {
snake_control::snake_control(abstract_factory const& factory)
: out{factory.make_snake_output()} {}

snake_control::snake_control(std::unique_ptr<snake_output> out)
: out{std::move(out)} {}
}
