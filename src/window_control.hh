#ifndef SNK_WINDOW_CONTROL_HH_
#define SNK_WINDOW_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "window_input.hh"
#include "window_output.hh"

namespace snk {
struct window_control {
  explicit window_control(abstract_factory const& factory);

private:
  std::unique_ptr<window_input> in;
  std::unique_ptr<window_output> out;
};
}

#endif
