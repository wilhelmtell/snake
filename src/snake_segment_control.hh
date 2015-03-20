#ifndef SNK_SNAKE_SEGMENT_CONTROL_HH_
#define SNK_SNAKE_SEGMENT_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "snake_segment_output.hh"
#include "rectangle.hh"

namespace snk {
struct snake_segment_control {
  explicit snake_segment_control(abstract_factory* factory);
  explicit snake_segment_control(std::unique_ptr<snake_segment_output> out);
  snake_segment_control(std::unique_ptr<snake_segment_output> out,
                        rectangle rect);

public:
  std::unique_ptr<snake_segment_output> out;
  rectangle rect;
};
}

#endif
