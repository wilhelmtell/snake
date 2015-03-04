#include "config.h"
#include "sdl_factory.hh"
#include "game_control.hh"

int main(int /*argc*/, char* /*argv*/ []) {
  snk::sdl_factory factory;
  snk::game_control control{factory};
  while(control.is_on()) control.tick();
}
