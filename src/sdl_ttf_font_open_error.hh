#ifndef SNK_SDL_TTF_FONT_OPEN_ERROR_HH_
#define SNK_SDL_TTF_FONT_OPEN_ERROR_HH_

#include <stdexcept>

namespace snk {
struct sdl_ttf_font_open_error : std::runtime_error {
  explicit sdl_ttf_font_open_error(char const* const m);
};
}

#endif
