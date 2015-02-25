#include "snake.hh"
#include <SDL2/SDL.h>
#include "game.hh"
#include "renderer.hh"

namespace {
auto const SNAKE_W = 10;
auto const SNAKE_H = 10;
auto const SNAKE_INTERVAL = 100;  // in ms
auto const SNAKE_SPEED = 1;       // px/frame
}

namespace snk {
snake::snake()
: rect{0, 0, SNAKE_W, SNAKE_H}
, last_move_time{0}
, velx{SNAKE_SPEED}
, vely{0} {}

void snake::handle_event(game const& g, SDL_Event const& e) {
  auto const t = SDL_GetTicks();
  if(t - last_move_time <= SNAKE_INTERVAL) return;
  if(e.type == SDL_KEYDOWN) {
    if(e.key.keysym.sym == SDLK_LEFT && rect.x - SNAKE_SPEED >= 0) {
      velx = velx == SNAKE_SPEED ? SNAKE_SPEED : -SNAKE_SPEED;
      vely = 0;
    } else if(e.key.keysym.sym == SDLK_RIGHT
              && rect.x + SNAKE_SPEED < g.window_w()) {
      velx = velx == -SNAKE_SPEED ? -SNAKE_SPEED : SNAKE_SPEED;
      vely = 0;
    } else if(e.key.keysym.sym == SDLK_UP && rect.y - SNAKE_SPEED >= 0) {
      velx = 0;
      vely = vely == SNAKE_SPEED ? SNAKE_SPEED : -SNAKE_SPEED;
    } else if(e.key.keysym.sym == SDLK_DOWN
              && rect.y + SNAKE_SPEED < g.window_h()) {
      velx = 0;
      vely = vely == -SNAKE_SPEED ? -SNAKE_SPEED : SNAKE_SPEED;
    }
    last_move_time = t;
  }
}

void snake::update(game const& g) {
  if(rect.x + velx >= 0 && rect.x + velx < g.window_w()) rect.x += velx;
  if(rect.y + vely >= 0 && rect.y + vely < g.window_h()) rect.y += vely;
}

void snake::draw(renderer const& r) const {
  SDL_SetRenderDrawColor(r.get(), 0x7f, 0x7f, 0x00, 0xff);
  SDL_RenderFillRect(r.get(), &rect);
}
}
