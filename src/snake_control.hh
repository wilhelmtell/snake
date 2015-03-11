#ifndef SNK_SNAKE_CONTROL_HH_
#define SNK_SNAKE_CONTROL_HH_

#include "abstract_factory_fwd.hh"
#include <memory>
#include "snake_output.hh"

namespace snk {
struct snake_control {
  explicit snake_control(abstract_factory const&);
  explicit snake_control(std::unique_ptr<snake_output> out);

private:
  std::unique_ptr<snake_output> out;
};
}

#endif
