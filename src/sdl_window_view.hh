#ifndef SNK_SDL_WINDOW_VIEW_HH_
#define SNK_SDL_WINDOW_VIEW_HH_

#include "window_view.hh"
#include "window.hh"

namespace snk {
struct sdl_window_view : window_view {
  sdl_window_view(int const& width, int const& height);

private:
  window w;
};
}

#endif
