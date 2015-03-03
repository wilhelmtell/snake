#ifndef SNK_SDL_RENDERER_OUTPUT_HH_
#define SNK_SDL_RENDERER_OUTPUT_HH_

#include "renderer_output.hh"
#include "sdl_window_handle_fwd.hh"
#include "sdl_renderer_handle.hh"

namespace snk {
struct sdl_renderer_output : renderer_output {
  sdl_renderer_output(sdl_window_handle const& w);

private:
  sdl_renderer_handle r;
};
}

#endif
