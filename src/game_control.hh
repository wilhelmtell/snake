#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include <memory>
#include "game_output.hh"
#include "abstract_factory_fwd.hh"
#include "event_dispatch_fwd.hh"
#include "snake_control.hh"
#include "berry_control.hh"

namespace snk {
struct game_control {
  game_control(abstract_factory* factory, event_dispatch* dispatch);
  game_control(std::unique_ptr<game_output> out,
               abstract_factory* factory,
               event_dispatch* dispatch);

  void update();
  void draw();

  bool game_over() const;

private:
  void on_keydown_esc();
  void on_keydown_p();
  void on_berry_eaten(point const& position);
  void on_pause_game();
  void on_resume_game();

private:
  abstract_factory* factory;
  std::unique_ptr<game_output> out;
  event_dispatch* dispatch;
  berry_control berry;
  snake_control snake;
  bool end_game_requested;
  bool game_paused;
};
}

#endif
