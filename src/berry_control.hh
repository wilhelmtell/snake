#ifndef SNK_BERRY_CONTROL_HH_
#define SNK_BERRY_CONTROL_HH_

#include <memory>
#include "abstract_factory_fwd.hh"
#include "berry_output.hh"
#include "event.hh"
#include "rectangle.hh"
#include "point_fwd.hh"
#include "width_fwd.hh"
#include "height_fwd.hh"

namespace snk {
struct berry_control {
  berry_control(abstract_factory* factory,
                point position,
                width berry_width,
                height berry_height);

  void handle_event(event const& e);
  void update();
  void draw();

  point position() const;

private:
  std::unique_ptr<berry_output> out;
  rectangle rect;
};
}

#endif
