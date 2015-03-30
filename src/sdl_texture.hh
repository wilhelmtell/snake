#ifndef SNK_SDL_TEXTURE_HH_
#define SNK_SDL_TEXTURE_HH_

#include <memory>
#include <SDL2/SDL.h>

namespace snk {
struct sdl_texture {
  explicit sdl_texture(SDL_Texture* t);

  SDL_Texture* get() const;

private:
  using pointer = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
  pointer t;
};
}

#endif
