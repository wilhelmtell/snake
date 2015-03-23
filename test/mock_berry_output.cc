#include "mock_berry_output.hh"
#include "rectangle.hh"

namespace snk {
namespace test {
void mock_berry_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_berry_output::draw_rect(rectangle const& /*rect*/) {}
}
}
