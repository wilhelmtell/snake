#ifndef SNK_SDL_RENDERER_VIEW_HH_
#define SNK_SDL_RENDERER_VIEW_HH_

#include "renderer_view.hh"
#include "renderer.hh"

namespace snk {
struct sdl_renderer_view : renderer_view {
  sdl_renderer_view(window const& w);

private:
  renderer r;
};
}

#endif
