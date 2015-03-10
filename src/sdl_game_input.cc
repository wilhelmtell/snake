#include "sdl_game_input.hh"
#include "game_control.hh"
#include <SDL2/SDL.h>

namespace snk {
sdl_game_input::sdl_game_input(game_control* const control)
: control{control} {}
}
