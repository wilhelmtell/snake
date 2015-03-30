#ifndef SNK_SDL_TEXTURE_CREATION_ERROR_HH_
#define SNK_SDL_TEXTURE_CREATION_ERROR_HH_

#include <stdexcept>

namespace snk {
struct sdl_texture_creation_error : std::runtime_error {
  explicit sdl_texture_creation_error(char const* const m);
};
}

#endif
