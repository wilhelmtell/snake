#include "config.h"
#include "sdl_game_input.hh"
#include "sdl_game_output.hh"
#include "game_control.hh"
#include "sdl_window_output.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_game_input input;
  snk::sdl_game_output output;
  snk::sdl_window_output w_o{640, 480};
  snk::game_control control{&input, &output, &w_o};
  output.controlled_by(&control);
  while(control.is_on()) control.tick();
}
