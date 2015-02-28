#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include "game_view_fwd.hh"

namespace snk {
struct game_control {
  explicit game_control(game_view* view);

  bool is_on() const;
};
}

#endif
