#ifndef SNK_GAME_HH_
#define SNK_GAME_HH_

#include "sdl.hh"

namespace snk {
struct game {
  game() = default;

private:
  sdl sdl_subsystem;
};
}

#endif
