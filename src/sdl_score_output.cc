#include "sdl_score_output.hh"
#include <utility>
#include <SDL2/SDL.h>

namespace snk {
sdl_score_output::sdl_score_output(SDL_Window* window, SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}
}
