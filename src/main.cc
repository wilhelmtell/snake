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
  snk::sdl app;
  if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    std::cerr << "error: linear texturing filtering not enabled.\n";
    return 1;
  }
  snk::window window{SDL_CreateWindow("Snake",
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      640,
                                      480,
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
  SDL_SetRenderDrawColor(renderer.get(), 0xff, 0xff, 0xff, 0xff);
  bool quit = false;
  while(!quit) {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      quit = e.type == SDL_QUIT;
    }
    SDL_SetRenderDrawColor(renderer.get(), 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
  }
}
