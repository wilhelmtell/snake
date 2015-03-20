#include "sdl_snake_segment_output.hh"
#include <utility>

namespace snk {
sdl_snake_segment_output::sdl_snake_segment_output(SDL_Window* window,
                                                   SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}
}
