#ifndef SNK_SDL_TTF_FONT_HH_
#define SNK_SDL_TTF_FONT_HH_

#include <memory>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cstddef>

namespace snk {
struct sdl_ttf_font {
  sdl_ttf_font(std::string const& name, std::size_t const& size);

  TTF_Font* get() const;

private:
  using pointer = std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)>;
  pointer f;
};
}

#endif
