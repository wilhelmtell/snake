#ifndef SNK_WINDOW_CONTROL_HH_
#define SNK_WINDOW_CONTROL_HH_

#include "abstract_factory_fwd.hh"

namespace snk {
struct window_control {
  explicit window_control(abstract_factory const& factory);
};
}

#endif
