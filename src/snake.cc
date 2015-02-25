#include "snake.hh"
#include <SDL2/SDL.h>
#include "game.hh"
#include "renderer.hh"

namespace {
auto const SNAKE_W = 10;
auto const SNAKE_H = 10;
}

namespace snk {
snake::snake() : rect{0, 0, SNAKE_W, SNAKE_H} {}

void snake::update(game const& g, SDL_Event const& e) {
  switch(e.type) {
  case SDL_KEYDOWN:
    if(e.key.keysym.sym == SDLK_LEFT && rect.x - 10 >= 0)
      rect.x -= 10;
    else if(e.key.keysym.sym == SDLK_RIGHT && rect.x + 10 < g.window_w())
      rect.x += 10;
    else if(e.key.keysym.sym == SDLK_UP && rect.y - 10 >= 0)
      rect.y -= 10;
    else if(e.key.keysym.sym == SDLK_DOWN && rect.y + 10 < g.window_h())
      rect.y += 10;
    break;
  }
}

void snake::draw(renderer const& r) const {
  SDL_SetRenderDrawColor(r.get(), 0x7f, 0x7f, 0x00, 0xff);
  SDL_RenderFillRect(r.get(), &rect);
}
}
