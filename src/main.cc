#include "config.h"
#include "sdl_game_view.hh"
#include "game_control.hh"
#include "sdl_window_view.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_game_view view;
  snk::sdl_window_view w_v{640, 480};
  snk::game_control control{&view, &w_v};
  view.controlled_by(&control);
  while(control.is_on()) control.tick();
}
