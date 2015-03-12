#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include <memory>
#include "game_output.hh"
#include "abstract_factory_fwd.hh"
#include "window_control.hh"
#include "event_fwd.hh"

namespace snk {
struct game_control {
  explicit game_control(abstract_factory const& factory);
  game_control(std::unique_ptr<game_output> output,
               abstract_factory const& factory);

  void handle_event(event const& e);
  void update();
  void draw();

private:
  std::unique_ptr<game_output> output;
  window_control w_c;
};
}

#endif
