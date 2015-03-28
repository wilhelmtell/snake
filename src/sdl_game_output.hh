#ifndef SNK_SDL_GAME_OUTPUT_HH_
#define SNK_SDL_GAME_OUTPUT_HH_

#include "game_output.hh"
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"
#include "sdl_ttf_font.hh"

namespace snk {
struct sdl_game_output : game_output {
  sdl_game_output(SDL_Window* window, SDL_Renderer* renderer);

  void draw_score(int score,
                  unsigned char r,
                  unsigned char g,
                  unsigned char b,
                  unsigned char a) override;
  void clear(int r, int g, int b, int a) override;
  void present() override;

  rectangle bounds() const override;

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  sdl_ttf_font score_font;
};
}

#endif
