#include "config.h"
#include "sdl.hh"
#include <SDL2/SDL.h>
#include <memory>
#include <iostream>

namespace snk {
using window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
}

int main(int /*argc*/, char * /*argv*/ []) {
  auto const WINDOW_W = 640;
  auto const WINDOW_H = 480;
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
  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
  SDL_Rect berry = {320, 240, 10, 10};
  while(true) {
    for(SDL_Event e; SDL_PollEvent(&e) != 0;) {
      switch(e.type) {
      case SDL_KEYDOWN:
        if(e.key.keysym.sym == SDLK_LEFT && berry.x - 25 >= 0)
          berry.x -= 25;
        else if(e.key.keysym.sym == SDLK_RIGHT && berry.x + 25 < WINDOW_W)
          berry.x += 25;
        else if(e.key.keysym.sym == SDLK_UP && berry.y - 25 >= 0)
          berry.y -= 25;
        else if(e.key.keysym.sym == SDLK_DOWN && berry.y + 25 < WINDOW_H)
          berry.y += 25;
        break;
      case SDL_QUIT:
        return 0;
      }
    }
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(), 0x7f, 0x7f, 0x7f, 0x7f);
    SDL_RenderFillRect(renderer.get(), &berry);
    SDL_RenderPresent(renderer.get());
  }
}
