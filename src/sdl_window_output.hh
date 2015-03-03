#ifndef SNK_SDL_WINDOW_OUTPUT_HH_
#define SNK_SDL_WINDOW_OUTPUT_HH_

#include "window_output.hh"
#include "window.hh"

namespace snk {
struct sdl_window_output : window_output {
  sdl_window_output(int const& width, int const& height);

private:
  window w;
};
}

#endif
