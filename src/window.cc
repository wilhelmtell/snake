#include "window.hh"
#include <SDL2/SDL.h>
#include "window_creation_error.hh"
#include <utility>

namespace snk {
auto const WINDOW_W = 640;
auto const WINDOW_H = 480;
}

namespace snk {
window::window()
: w{SDL_CreateWindow("Snake",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     WINDOW_W,
                     WINDOW_H,
                     SDL_WINDOW_SHOWN)} {
  if(w == nullptr) throw window_creation_error(SDL_GetError());
}

window::window(window&& rhs) : w(rhs.release()) {}

window& window::operator=(window&& rhs) {
  reset(rhs.release());
  return *this;
}

window::~window() {
  if(w != nullptr) SDL_DestroyWindow(w);
}

SDL_Window* window::get() const { return w; }

SDL_Window* window::release() {
  auto p = get();
  w = nullptr;
  return p;
}

void window::reset(SDL_Window* p) {
  using std::swap;
  swap(w, p);
  if(p != nullptr) SDL_DestroyWindow(p);
}
}
