#include "mock_snake_output.hh"
#include <cassert>

namespace snk {
namespace test {
mock_snake_output::mock_snake_output() : position_initialized{false} {}

bool mock_snake_output::at_position(position const& pos) const {
  return position_initialized && this->pos == pos;
}

void mock_snake_output::get_drawable_size(int* w, int* h) {
  assert(w != nullptr);  // SDL allows for nulls, but I don't
  assert(h != nullptr);
  *w = 640;
  *h = 480;
}

void mock_snake_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_snake_output::draw_rect(position pos, int w, int h) {
  position_initialized = true;
  this->pos.x = pos.x;
  this->pos.y = pos.y;
  this->w = w;
  this->h = h;
}
}
}
