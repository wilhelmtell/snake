#include "mock_snake_output.hh"

namespace snk {
namespace test {
bool mock_snake_output::at_position(int x, int y) const {
  return x == this->x && y == this->y;
}

void mock_snake_output::get_drawable_size(int* /*w*/, int* /*h*/) {}

void mock_snake_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_snake_output::draw_rect(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}
}
}
