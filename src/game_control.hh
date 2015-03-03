#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include "game_output_fwd.hh"
#include "game_input_fwd.hh"
#include "window_output_fwd.hh"
#include "window_input_fwd.hh"
#include "window_control.hh"

namespace snk {
struct game_control {
  game_control(game_input* input, game_output* output, window_output* w_o);

  void notify_end();
  bool is_on() const;
  void tick();

private:
  game_input* input;
  game_output* output;
  window_control w_c;
};
}

#endif
