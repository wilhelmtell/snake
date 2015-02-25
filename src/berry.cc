#include "berry.hh"
#include <SDL2/SDL.h>
#include "game.hh"
#include "renderer.hh"

namespace {
int const BERRY_H = 10;
int const BERRY_W = 10;
unsigned int const BERRY_INTERVAL = 30000;  // ms
}

namespace snk {
berry::berry()
: rect{0, 0, BERRY_W, BERRY_H}, last_berry_time{SDL_GetTicks()} {}

void berry::update(game const& /*g*/, SDL_Event const& /*e*/) {
  auto const t = SDL_GetTicks();
  if(t - last_berry_time > BERRY_INTERVAL) {
    rect = {0, 0, BERRY_W, BERRY_H};
    last_berry_time = t;
  }
}

void berry::draw(renderer const& r) const {
  SDL_SetRenderDrawColor(r.get(), 0x7f, 0x00, 0xff, 0xff);
  SDL_RenderFillRect(r.get(), &rect);
}
}
