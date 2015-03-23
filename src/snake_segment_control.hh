#ifndef SNK_SNAKE_SEGMENT_CONTROL_HH_
#define SNK_SNAKE_SEGMENT_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "snake_segment_output.hh"
#include "rectangle.hh"
#include "event_fwd.hh"

namespace snk {
struct snake_segment_control {
  snake_segment_control(abstract_factory* factory,
                        point position,
                        width segment_width,
                        height segment_height);

  snake_segment_control(std::unique_ptr<snake_segment_output> out,
                        point position,
                        width segment_width,
                        height segment_height);

  void handle_event(event const& e);
  void update();
  void draw() const;

  point position() const;
  bool intersect(rectangle const& rect) const;
  bool outside(rectangle const& bounds) const;

public:
  std::unique_ptr<snake_segment_output> out;
  rectangle rect;
};
}

#endif
