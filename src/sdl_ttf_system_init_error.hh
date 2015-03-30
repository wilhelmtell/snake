#ifndef SNK_SDL_TTF_SYSTEM_INIT_ERROR_HH_
#define SNK_SDL_TTF_SYSTEM_INIT_ERROR_HH_

#include <stdexcept>

namespace snk {
struct sdl_ttf_system_init_error : std::runtime_error {
  explicit sdl_ttf_system_init_error(char const* const m);
};
}

#endif
