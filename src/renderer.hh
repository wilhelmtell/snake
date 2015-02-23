#ifndef SNK_RENDERER_HH_
#define SNK_RENDERER_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
struct window;
}

namespace snk {
struct renderer {
  renderer(window const& w);

  SDL_Renderer* get() const;

private:
  using pointer
    = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
  pointer r;
};
}

#endif
