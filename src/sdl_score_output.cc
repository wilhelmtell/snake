#include "sdl_score_output.hh"
#include <utility>
#include <SDL2/SDL.h>
#include <string>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"
#include "sdl_surface.hh"
#include "sdl_texture.hh"

namespace snk {
sdl_score_output::sdl_score_output(SDL_Window* window, SDL_Renderer* renderer)
: window{std::move(window)}
, renderer{std::move(renderer)}
, score_font{"data/Arial.ttf", 28} {}

void sdl_score_output::draw_text(std::string const& text,
                                 unsigned char r,
                                 unsigned char g,
                                 unsigned char b,
                                 unsigned char a) {
  sdl_surface const surface{TTF_RenderText_Blended(
    score_font.get(), text.c_str(), SDL_Color{r, g, b, a})};
  sdl_texture const texture{
    SDL_CreateTextureFromSurface(renderer, surface.get())};
  auto const box = rectangle{point{10, bounds().h - surface.get()->h - 10},
                             width{surface.get()->w},
                             height{surface.get()->h}};
  SDL_Rect const quad{box.p.x, box.p.y, box.w, box.h};
  SDL_RenderCopy(renderer, texture.get(), nullptr, &quad);
}

rectangle sdl_score_output::bounds() const {
  int w, h;
  SDL_GL_GetDrawableSize(window, &w, &h);
  return rectangle{point{0, 0}, width{w}, height{h}};
}
}
