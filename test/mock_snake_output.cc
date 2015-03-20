#include "mock_snake_output.hh"
#include <cassert>
#include "rectangle.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
namespace test {
mock_snake_output::mock_snake_output()
: mock_snake_output{snk::rectangle{position{0, 0}, width{640}, height{480}}} {}

mock_snake_output::mock_snake_output(snk::rectangle const& drawable_rect)
: position_initialized{false}, drawable_rect{drawable_rect} {}

bool mock_snake_output::at_position(snk::position const& pos) const {
  return position_initialized && this->pos == pos;
}

snk::rectangle mock_snake_output::get_drawable_size() const {
  return drawable_rect;
}

void mock_snake_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_snake_output::draw_rect(snk::position const& pos,
                                  snk::rectangle const& rect) {
  position_initialized = true;
  this->pos.x = pos.x;
  this->pos.y = pos.y;
  this->rect.w = rect.w;
  this->rect.h = rect.h;
}
}
}
