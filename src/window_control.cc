#include "window_control.hh"
#include "abstract_factory.hh"
#include "window_output.hh"

namespace snk {
window_control::window_control(abstract_factory const& factory)
: out{factory.make_window_output()} {}
}
