#ifndef SNK_SCORE_CONTROL_HH_
#define SNK_SCORE_CONTROL_HH_

#include <memory>
#include "event_dispatch_fwd.hh"
#include "abstract_factory_fwd.hh"
#include "score_output.hh"

namespace snk {
struct score_control {
  score_control(event_dispatch* dispatch, abstract_factory* factory);
  score_control(event_dispatch* dispatch,
                abstract_factory* factory,
                std::unique_ptr<score_output> out);

  void update();
  void draw() const;

private:
  std::unique_ptr<score_output> out;
};
}

#endif
