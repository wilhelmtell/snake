#ifndef SNK_GAME_OUTPUT_HH_
#define SNK_GAME_OUTPUT_HH_

#include "game_control_fwd.hh"

namespace snk {
struct game_output {
  virtual ~game_output() {}
  virtual void controlled_by(game_control* const control) = 0;
};
}

#endif
