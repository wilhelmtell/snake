#include "sdl_renderer_view.hh"
#include "sdl_window_handle.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_renderer_view::sdl_renderer_view(sdl_window_handle const& w)
: r{w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC} {}
}
