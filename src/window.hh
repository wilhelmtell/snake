#ifndef SNK_WINDOW_HH_
#define SNK_WINDOW_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
extern int const WINDOW_W;
extern int const WINDOW_H;

struct window {
  window();

  SDL_Window* get() const;

private:
  using pointer = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
  pointer w;
};
}

#endif
