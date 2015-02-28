#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include "game_view_fwd.hh"
#include "window_view_fwd.hh"
#include "window_control.hh"

namespace snk {
struct game_control {
  game_control(game_view* view, window_view* w_v);

  void notify_end();
  bool is_on() const;
  void tick();

private:
  game_view* view;
  window_control w_c;
};
}

#endif
