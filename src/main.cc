#include "config.h"
#include "sdl.hh"
#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <random>

namespace snk {
using window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
}

int main(int /*argc*/, char * /*argv*/ []) {
  auto const WINDOW_W = 640;
  auto const WINDOW_H = 480;
  auto const BERRY_W = 10;
  auto const BERRY_H = 10;
  auto const BERRY_INTERVAL = 30000;  // ms
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> xdist{0, WINDOW_W};
  std::uniform_int_distribution<> ydist{0, WINDOW_H};
  snk::sdl app;
  if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    std::cerr << "error: linear texturing filtering not enabled.\n";
    return 1;
  }
  snk::window window{SDL_CreateWindow("Snake",
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      WINDOW_W,
                                      WINDOW_H,
                                      SDL_WINDOW_SHOWN),
                     SDL_DestroyWindow};
  if(window == nullptr) {
    std::cerr << "error: failed creating window.\n";
    return 1;
  }
  snk::renderer renderer{
    SDL_CreateRenderer(
      window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
    SDL_DestroyRenderer};
  if(renderer == nullptr) {
    std::cerr << "error: failed creating renderer.\n";
    return 1;
  }
  auto berry_show_time = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
  auto const random_x = [&]() {
    auto const x = xdist(gen);
    return x - (x % BERRY_W);
  };
  auto const random_y = [&]() {
    auto const y = ydist(gen);
    return y - (y % BERRY_H);
  };
  SDL_Rect berry = {random_x(), random_y(), BERRY_W, BERRY_H};
  SDL_Rect snake = {random_x(), random_y(), BERRY_W, BERRY_H};
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      if(e.type == SDL_QUIT) return 0;
    }
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
    SDL_RenderClear(renderer.get());
    auto const t = SDL_GetTicks();
    if(t - berry_show_time > BERRY_INTERVAL) {
      berry = {random_x(), random_y(), BERRY_W, BERRY_H};
      berry_show_time = t;
    }
    SDL_SetRenderDrawColor(renderer.get(), 0x7f, 0x00, 0xff, 0xff);
    SDL_RenderFillRect(renderer.get(), &berry);
    SDL_SetRenderDrawColor(renderer.get(), 0x7f, 0x7f, 0x00, 0xff);
    SDL_RenderFillRect(renderer.get(), &snake);
    SDL_RenderPresent(renderer.get());
  }
}
