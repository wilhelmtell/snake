#include "config.h"
#include "game.hh"
#include "window.hh"
#include "renderer.hh"
#include "berry.hh"
#include "snake.hh"
#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <random>

int main(int /*argc*/, char * /*argv*/ []) {
  // setup
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> xdist{0, snk::WINDOW_W};
  std::uniform_int_distribution<> ydist{0, snk::WINDOW_H};
  snk::game g;
  snk::window window;
  snk::renderer renderer{window};
  auto berry_show_time = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
  auto const random_x = [&]() {
    auto const x = xdist(gen);
    return x - (x % snk::BERRY_W);
  };
  auto const random_y = [&]() {
    auto const y = ydist(gen);
    return y - (y % snk::BERRY_H);
  };
  snk::berry berry = {random_x(), random_y(), snk::BERRY_W, snk::BERRY_H};
  snk::snake snake = {random_x(), random_y(), snk::BERRY_W, snk::BERRY_H};

  // input
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      switch(e.type) {
      case SDL_KEYDOWN:
        if(e.key.keysym.sym == SDLK_LEFT && snake.x - 10 >= 0)
          snake.x -= 10;
        else if(e.key.keysym.sym == SDLK_RIGHT && snake.x + 10 < snk::WINDOW_W)
          snake.x += 10;
        else if(e.key.keysym.sym == SDLK_UP && snake.y - 10 >= 0)
          snake.y -= 10;
        else if(e.key.keysym.sym == SDLK_DOWN && snake.y + 10 < snk::WINDOW_H)
          snake.y += 10;
        break;
      case SDL_QUIT:
        return 0;
      }
    }

    // update
    auto const t = SDL_GetTicks();
    if(t - berry_show_time > snk::BERRY_INTERVAL) {
      berry = {random_x(), random_y(), snk::BERRY_W, snk::BERRY_H};
      berry_show_time = t;
    }

    // draw
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(), 0x7f, 0x00, 0xff, 0xff);
    SDL_RenderFillRect(renderer.get(), &berry);
    SDL_SetRenderDrawColor(renderer.get(), 0x7f, 0x7f, 0x00, 0xff);
    SDL_RenderFillRect(renderer.get(), &snake);
    SDL_RenderPresent(renderer.get());
  }
}
