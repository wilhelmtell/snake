#include "sdl_game_output.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "rectangle.hh"
#include "point.hh"
#include "width.hh"
#include "height.hh"
#include <boost/lexical_cast.hpp>
#include <string>
#include "sdl_surface.hh"
#include "sdl_texture.hh"

namespace snk {
sdl_game_output::sdl_game_output(SDL_Window* window, SDL_Renderer* renderer)
: window{window}, renderer{renderer}, score_font{"data/Arial.ttf", 18} {}

void sdl_game_output::draw_score(int score,
                                 unsigned char r,
                                 unsigned char g,
                                 unsigned char b,
                                 unsigned char a) {
  sdl_surface const surface{
    TTF_RenderText_Solid(score_font.get(),
                         boost::lexical_cast<std::string>(score).c_str(),
                         SDL_Color{r, g, b, a})};
  sdl_texture const texture{
    SDL_CreateTextureFromSurface(renderer, surface.get())};
  SDL_Rect const quad = {
    10, bounds().h - surface.get()->h - 5, surface.get()->w, surface.get()->h};
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
