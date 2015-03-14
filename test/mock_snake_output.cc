#include "mock_snake_output.hh"
#include <cassert>
#include "rectangle.hh"

namespace snk {
namespace test {
mock_snake_output::mock_snake_output() : position_initialized{false} {}

bool mock_snake_output::at_position(position const& pos) const {
  return position_initialized && this->pos == pos;
}

void mock_snake_output::get_drawable_size(rectangle* rect) {
  assert(rect != nullptr);  // SDL allows for nulls, but I don't
  rect->w = 640;
  rect->h = 480;
}

void mock_snake_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_snake_output::draw_rect(position pos, rectangle rect) {
  position_initialized = true;
  this->pos.x = pos.x;
  this->pos.y = pos.y;
  this->w = rect.w;
  this->h = rect.h;
}
}
}
