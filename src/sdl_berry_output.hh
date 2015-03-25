#ifndef SNK_SDL_BERRY_OUTPUT_HH_
#define SNK_SDL_BERRY_OUTPUT_HH_

#include "berry_output.hh"
#include <SDL2/SDL.h>
#include "rectangle_fwd.hh"

namespace snk {
struct sdl_berry_output : berry_output {
  sdl_berry_output(SDL_Window* window, SDL_Renderer* renderer);

  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(rectangle const& rect) override;
  rectangle bounds() const override;

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}

#endif
