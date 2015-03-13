#ifndef SNK_SDL_SNAKE_OUTPUT_HH_
#define SNK_SDL_SNAKE_OUTPUT_HH_

#include "snake_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_snake_output : snake_output {
  sdl_snake_output(SDL_Renderer* r, SDL_Window* w);

  void get_drawable_size(int* w, int* h) override;
  void set_colour(int r, int g, int b, int a) override;
  void draw_rect(int x, int y, int w, int h) override;

private:
  SDL_Renderer* r;
  SDL_Window* w;
};
}

#endif
