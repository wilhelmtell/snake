#include "berry.hh"
#include <SDL2/SDL.h>
#include "game.hh"
#include "renderer.hh"
#include <random>

namespace {
int const BERRY_H = 10;
int const BERRY_W = 10;
unsigned int const BERRY_INTERVAL = 30000;  // ms

int random_x(int max) {
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> dist{0, max};
  auto const x = dist(gen);
  return x - (x % BERRY_W);
}

int random_y(int max) {
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> dist{0, max};
  auto const y = dist(gen);
  return y - (y % BERRY_H);
}
}

namespace snk {
berry::berry()
: rect{0, 0, BERRY_W, BERRY_H}
, last_berry_time{SDL_GetTicks() - BERRY_INTERVAL} {}

void berry::handle_event(game const& /*g*/, SDL_Event const& /*e*/) {}

void berry::update(game const& g) {
  auto const t = SDL_GetTicks();
  if(t - last_berry_time > BERRY_INTERVAL) {
    rect = {random_x(g.window_w()), random_y(g.window_h()), BERRY_W, BERRY_H};
    last_berry_time = t;
  }
}

void berry::draw(renderer const& r) const {
  SDL_SetRenderDrawColor(r.get(), 0x7f, 0x00, 0xff, 0xff);
  SDL_RenderFillRect(r.get(), &rect);
}
}
