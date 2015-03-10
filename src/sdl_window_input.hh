#ifndef SNK_SDL_WINDOW_INPUT_HH_
#define SNK_SDL_WINDOW_INPUT_HH_

#include "window_input.hh"
#include "window_control_fwd.hh"

namespace snk {
struct sdl_window_input : window_input {
  explicit sdl_window_input(window_control* const control);
};
}

#endif
