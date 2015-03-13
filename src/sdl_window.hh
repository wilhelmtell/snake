#ifndef SNK_SDL_WINDOW_HANDLE_HH_
#define SNK_SDL_WINDOW_HANDLE_HH_

#include <memory>
#include <SDL2/SDL.h>
#include "position_fwd.hh"

namespace snk {
struct sdl_window {
  sdl_window(char const* const title,
             position const& pos,
             int const& width,
             int const& height,
             int const& flags);

  SDL_Window* get() const;

private:
  using pointer = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
  pointer w;
};
}

#endif
