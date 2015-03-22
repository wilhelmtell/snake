#include "sdl_snake_segment_output.hh"
#include <utility>
#include <SDL2/SDL.h>
#include "rectangle.hh"

namespace snk {
sdl_snake_segment_output::sdl_snake_segment_output(SDL_Window* window,
                                                   SDL_Renderer* renderer)
: window{std::move(window)}, renderer{std::move(renderer)} {}

void sdl_snake_segment_output::set_colour(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void sdl_snake_segment_output::draw_rect(rectangle const& rect) {
  SDL_Rect sdl_rect{rect.p.x, rect.p.y, rect.w, rect.h};
  SDL_RenderFillRect(renderer, &sdl_rect);
}
}
