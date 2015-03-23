#ifndef SNK_SDL_GAME_OUTPUT_HH_
#define SNK_SDL_GAME_OUTPUT_HH_

#include "game_output.hh"
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"

namespace snk {
struct sdl_game_output : game_output {
  sdl_game_output(SDL_Window* w, SDL_Renderer* r);

  void clear(int r, int g, int b, int a) override;
  void present() override;

  rectangle bounds() const override;

private:
  SDL_Window* w;
  SDL_Renderer* r;
};
}

#endif
