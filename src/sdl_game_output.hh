#ifndef SNK_SDL_GAME_OUTPUT_HH_
#define SNK_SDL_GAME_OUTPUT_HH_

#include "game_output.hh"
#include <SDL2/SDL.h>

namespace snk {
struct sdl_game_output : game_output {
  explicit sdl_game_output(SDL_Renderer* renderer);
};
}

#endif
