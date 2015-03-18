#ifndef SNK_GAME_CONTROL_HH_
#define SNK_GAME_CONTROL_HH_

#include <memory>
#include "game_output.hh"
#include "abstract_factory_fwd.hh"
#include "event_fwd.hh"
#include "snake_control.hh"
#include "berry_control.hh"

namespace snk {
struct game_control {
  explicit game_control(abstract_factory* factory);
  game_control(std::unique_ptr<game_output> out,
               abstract_factory* factory);

  void handle_event(event const& e);
  void update();
  void draw();

  bool game_over() const;

private:
  std::unique_ptr<game_output> out;
  snake_control snake;
  bool end_game_requested;
};
}

#endif
