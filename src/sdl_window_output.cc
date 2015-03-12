#include "sdl_window_output.hh"

namespace snk {
sdl_window_output::sdl_window_output(int const& width, int const& height)
: w{"Snake",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width,
    height,
    SDL_WINDOW_SHOWN} {}
}
