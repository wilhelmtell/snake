#include "sdl_renderer_output.hh"
#include "sdl_window_handle.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_renderer_output::sdl_renderer_output(sdl_window_handle const& w)
: r{w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC} {}
}
