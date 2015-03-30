#include "sdl_texture.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_texture::sdl_texture(SDL_Texture* t) : t{t, &SDL_DestroyTexture} {}

SDL_Texture* sdl_texture::get() const { return t.get(); }
}
