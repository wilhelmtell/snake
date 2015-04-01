#ifndef SNK_SCORE_CONTROL_HH_
#define SNK_SCORE_CONTROL_HH_

#include <memory>
#include "event_dispatch_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "score_output.hh"
#include "point_fwd.hh"

namespace snk {
struct score_control {
  score_control(event_dispatch* dispatch, abstract_factory* factory);
  score_control(event_dispatch* dispatch,
                abstract_factory* factory,
                std::unique_ptr<score_output> out);

  void update();
  void draw() const;

private:
  void on_berry_eaten(point const& position);
  void on_restart();

private:
  std::unique_ptr<score_output> out;
  int value;
};
}

#endif
