#ifndef SNK_SDL_RENDERER_HANDLE_HH_
#define SNK_SDL_RENDERER_HANDLE_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
struct sdl_window_handle;
}

namespace snk {
struct sdl_renderer_handle {
  sdl_renderer_handle(sdl_window_handle const& w,
                      int const& index,
                      int const& flags);

  SDL_Renderer* get() const;

private:
  using pointer
    = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
  pointer r;
};
}

#endif
