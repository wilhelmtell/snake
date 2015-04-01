#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include <memory>
#include "game_output.hh"
#include "abstract_factory_fwd.hh"
#include "event_dispatch_fwd.hh"
#include "snake_control.hh"
#include "berry_control.hh"
#include "score_control.hh"

namespace snk {
struct game_control {
  game_control(event_dispatch* dispatch, abstract_factory* factory);
  game_control(event_dispatch* dispatch,
               abstract_factory* factory,
               std::unique_ptr<game_output> out);

  void update();
  void draw() const;

private:
  void on_keydown_esc();
  void on_keydown_p();
  void on_berry_eaten(point const& position);
  void on_toggle_pause();

private:
  event_dispatch* dispatch;
  abstract_factory* factory;
  std::unique_ptr<game_output> out;
  berry_control berry;
  snake_control snake;
  score_control score;
  bool game_paused;
};
}

#endif
