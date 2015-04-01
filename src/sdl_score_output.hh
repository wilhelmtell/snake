#ifndef SNK_SDL_SCORE_OUTPUT_HH_
#define SNK_SDL_SCORE_OUTPUT_HH_

#include "score_output.hh"
#include <SDL2/SDL.h>
#include "sdl_ttf_font.hh"
#include "rectangle_fwd.hh"
#include <string>

namespace snk {
struct sdl_score_output : score_output {
  sdl_score_output(SDL_Window* window, SDL_Renderer* renderer);

  void draw_text(std::string const& text,
                 unsigned char r,
                 unsigned char g,
                 unsigned char b,
                 unsigned char a) override;
  rectangle bounds() const override;

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  sdl_ttf_font score_font;
};
}

#endif
