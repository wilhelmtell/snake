#include "snake_control.hh"
#include "abstract_factory.hh"

namespace snk {
snake_control::snake_control(abstract_factory const& factory)
: in{factory.make_snake_input(this)}, out{factory.make_snake_output()} {}

snake_control::snake_control(std::unique_ptr<snake_input> in,
                             std::unique_ptr<snake_output> out)
: in{std::move(in)}, out{std::move(out)} {}
}
