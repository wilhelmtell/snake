#include "sdl_ttf_font.hh"
#include "sdl_ttf_font_open_error.hh"
#include <SDL2/SDL_ttf.h>
#include <cstddef>

namespace snk {
sdl_ttf_font::sdl_ttf_font(std::string const& name, std::size_t const& size)
: f{TTF_OpenFont(name.c_str(), size), TTF_CloseFont} {
  if(f == nullptr) throw sdl_ttf_font_open_error{TTF_GetError()};
}

TTF_Font* sdl_ttf_font::get() const { return f.get(); }
}
