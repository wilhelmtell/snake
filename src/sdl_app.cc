#include "sdl_app.hh"
#include <SDL2/SDL.h>
#include "handle_sdl_event.hh"

namespace snk {
sdl_app::sdl_app()
: dispatch{}, sdl{&dispatch}, factory{}, game{&dispatch, &factory} {}

void sdl_app::handle_event(SDL_Event const& e) {
  handle_sdl_event(dispatch, e);
}

void sdl_app::update() { game.update(); }

void sdl_app::draw() const { game.draw(); }
}
