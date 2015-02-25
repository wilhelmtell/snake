#ifndef SNK_WINDOW_HH_
#define SNK_WINDOW_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
struct window {
  window(int const& width, int const& height);

  SDL_Window* get() const;

private:
  using pointer = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
  pointer w;
};
}

#endif
