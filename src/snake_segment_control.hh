#ifndef SNK_SNAKE_SEGMENT_CONTROL_HH_
#define SNK_SNAKE_SEGMENT_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "snake_segment_output.hh"
#include "event_dispatch_fwd.hh"
#include "rectangle.hh"

namespace snk {
struct snake_segment_control {
  snake_segment_control(abstract_factory* factory,
                        event_dispatch* dispatch,
                        point position,
                        width segment_width,
                        height segment_height);

  snake_segment_control(std::unique_ptr<snake_segment_output> out,
                        event_dispatch* dispatch,
                        point position,
                        width segment_width,
                        height segment_height);

  void update();
  void draw() const;

  point position() const;
  bool outside(rectangle const& bounds) const;
  bool hit(snake_segment_control const& seg) const;

public:
  std::unique_ptr<snake_segment_output> out;
  rectangle rect;
};
}

#endif
