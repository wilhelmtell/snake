#include "game.hh"
#include <SDL2/SDL.h>

namespace snk {
game::game() : w{window_w(), window_h()}, r{w} {}

int game::window_w() const { return 640; }
int game::window_h() const { return 480; }

void game::handle_event(SDL_Event const& e) {
  b.handle_event(*this, e);
  s.handle_event(*this, e);
}

void game::update() {
  b.update(*this);
  s.update(*this);
}

void game::draw() const {
  SDL_SetRenderDrawColor(r.get(), 0, 0, 0, 0xff);
  SDL_RenderClear(r.get());
  b.draw(r);
  s.draw(r);
  SDL_RenderPresent(r.get());
}
}
