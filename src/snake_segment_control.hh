#ifndef SNK_SNAKE_SEGMENT_CONTROL_HH_
#define SNK_SNAKE_SEGMENT_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "snake_segment_output.hh"
#include "rectangle.hh"
#include "event_fwd.hh"

namespace snk {
struct snake_segment_control {
  explicit snake_segment_control(abstract_factory* factory);
  explicit snake_segment_control(std::unique_ptr<snake_segment_output> out);
  snake_segment_control(std::unique_ptr<snake_segment_output> out,
                        rectangle rect);

  void handle_event(event const& e);
  void update();
  void draw() const;

  bool intersect(rectangle const& rect) const;

public:
  std::unique_ptr<snake_segment_output> out;
  rectangle rect;
};
}

#endif
