#include "mock_snake_output.hh"
#include <cassert>

namespace snk {
namespace test {
mock_snake_output::mock_snake_output() : position_initialized{false} {}

bool mock_snake_output::at_position(int x, int y) const {
  return position_initialized && x == this->x && y == this->y;
}

void mock_snake_output::get_drawable_size(int* w, int* h) {
  assert(w != nullptr);
  assert(h != nullptr);
  *w = 640;
  *h = 480;
}

void mock_snake_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_snake_output::draw_rect(int x, int y, int w, int h) {
  position_initialized = true;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}
}
}
