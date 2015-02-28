#ifndef SNK_GAME_VIEW_HH_
#define SNK_GAME_VIEW_HH_

#include "game_control_fwd.hh"

namespace snk {
struct game_view {
  virtual ~game_view() {}
  virtual void controlled_by(game_control* const control) = 0;
  virtual void tick() = 0;
};
}

#endif
