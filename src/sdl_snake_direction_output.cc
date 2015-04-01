#include "sdl_snake_direction_output.hh"
#include <utility>
#include <SDL2/SDL.h>

namespace snk {
sdl_snake_direction_output::sdl_snake_direction_output(SDL_Window* window,
                                                       SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}
}
