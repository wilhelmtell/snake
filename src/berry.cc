#include "berry.hh"
#include <SDL2/SDL.h>
#include "game.hh"

namespace snk {
int const BERRY_H = 10;
int const BERRY_W = 10;
unsigned int const BERRY_INTERVAL = 30000;  // ms

void berry::update(game const& /*g*/, SDL_Event const& /*e*/) {}

void berry::draw() const {}
}
