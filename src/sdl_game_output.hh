#ifndef SNK_SDL_GAME_OUTPUT_HH_
#define SNK_SDL_GAME_OUTPUT_HH_

#include "game_output.hh"
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"
#include "sdl_ttf_font.hh"
#include <functional>

namespace snk {
struct sdl_game_output : game_output {
  sdl_game_output(SDL_Window* window, SDL_Renderer* renderer);

  void draw_text(std::string const& text,
                 unsigned char r,
                 unsigned char g,
                 unsigned char b,
                 unsigned char a,
                 std::function<rectangle(width const&, height const&)>
                   bounding_box) override;
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
