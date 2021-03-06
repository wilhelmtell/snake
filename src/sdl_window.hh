#ifndef SNK_SDL_WINDOW_HANDLE_HH_
#define SNK_SDL_WINDOW_HANDLE_HH_

#include <memory>
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"

namespace snk {
struct sdl_window {
  sdl_window(char const* const title,
             rectangle const& bounds,
             int const& flags);

  SDL_Window* get() const;

private:
  using pointer = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
  pointer w;
};
}

#endif
