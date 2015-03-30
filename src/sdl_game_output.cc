#include "sdl_game_output.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"
#include <string>
#include "sdl_surface.hh"
#include "sdl_texture.hh"
#include <functional>

namespace snk {
sdl_game_output::sdl_game_output(SDL_Window* window, SDL_Renderer* renderer)
: window{window}, renderer{renderer}, score_font{"data/Arial.ttf", 18} {}

void sdl_game_output::draw_text(
  std::string const& text,
  unsigned char r,
  unsigned char g,
  unsigned char b,
  unsigned char a,
  std::function<rectangle(width const&, height const&)> bounding_box) {
  sdl_surface const surface{TTF_RenderText_Solid(
    score_font.get(), text.c_str(), SDL_Color{r, g, b, a})};
  sdl_texture const texture{
    SDL_CreateTextureFromSurface(renderer, surface.get())};
  auto const box
    = bounding_box(width{surface.get()->w}, height{surface.get()->h});
  SDL_Rect const quad{box.p.x, box.p.y, box.w, box.h};
  SDL_RenderCopyEx(
    renderer, texture.get(), nullptr, &quad, 0, nullptr, SDL_FLIP_NONE);
}

void sdl_game_output::clear(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderClear(renderer);
}

void sdl_game_output::present() { SDL_RenderPresent(renderer); }

rectangle sdl_game_output::bounds() const {
  int w, h;
  SDL_GL_GetDrawableSize(window, &w, &h);
  return rectangle{point{0, 0}, width{w}, height{h}};
}
}
