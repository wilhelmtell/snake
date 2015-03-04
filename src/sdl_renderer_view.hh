#ifndef SNK_SDL_RENDERER_VIEW_HH_
#define SNK_SDL_RENDERER_VIEW_HH_

#include "renderer_view.hh"
#include "sdl_window_handle_fwd.hh"
#include "sdl_renderer_handle.hh"

namespace snk {
struct sdl_renderer_view : renderer_view {
  sdl_renderer_view(sdl_window_handle const& w);

private:
  sdl_renderer_handle r;
};
}

#endif
