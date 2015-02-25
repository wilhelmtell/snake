#include "game.hh"
#include <SDL2/SDL.h>

namespace snk {
game::game() : w{window_w(), window_h()}, r{w} {}

int game::window_w() const { return 640; }
int game::window_h() const { return 480; }

void game::update(SDL_Event const& e) {
  b.update(*this, e);
  s.update(*this, e);
}

void game::draw() const {
  SDL_SetRenderDrawColor(r.get(), 0, 0, 0, 0);
  SDL_RenderClear(r.get());
  b.draw(r);
  s.draw(r);
  SDL_RenderPresent(r.get());
}
}
