#include "mock_snake_segment_output.hh"
#include "rectangle.hh"

namespace snk {
namespace test {
void mock_snake_segment_output::set_colour(int /*r*/,
                                           int /*g*/,
                                           int /*b*/,
                                           int /*a*/) {}

void mock_snake_segment_output::draw_rect(snk::rectangle const& /*rect*/) {}
}
}
