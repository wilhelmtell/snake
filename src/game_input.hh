#ifndef SNK_GAME_INPUT_HH_
#define SNK_GAME_INPUT_HH_

#include "game_control_fwd.hh"

namespace snk {
struct game_input {
  virtual ~game_input() {}
  virtual void controlled_by(game_control* const control) = 0;
  virtual void tick() = 0;
};
}

#endif
