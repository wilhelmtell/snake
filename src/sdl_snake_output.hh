#ifndef SNK_SDL_SNAKE_OUTPUT_HH_
#define SNK_SDL_SNAKE_OUTPUT_HH_

#include "snake_output.hh"
#include "position_fwd.hh"
#include "rectangle_fwd.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_snake_output : snake_output {
  sdl_snake_output(SDL_Renderer* r, SDL_Window* w);

  rectangle get_drawable_size() override;
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(position const& pos, rectangle const& rect) override;

private:
  SDL_Renderer* r;
  SDL_Window* w;
};
}

#endif
