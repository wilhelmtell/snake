#ifndef SNK_SDL_SCORE_OUTPUT_HH_
#define SNK_SDL_SCORE_OUTPUT_HH_

#include "score_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_score_output : score_output {
  sdl_score_output(SDL_Window* window, SDL_Renderer* renderer);

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}

#endif
