#include "mock_berry_output.hh"
#include <utility>
#include "rectangle.hh"

namespace snk {
namespace test {
mock_berry_output::mock_berry_output(rectangle bounding_rect)
: bounding_rect{std::move(bounding_rect)} {}

void mock_berry_output::set_colour(int /*r*/,
                                   int /*g*/,
                                   int /*b*/,
                                   int /*a*/) {}

void mock_berry_output::draw_rect(rectangle const& /*rect*/) {}

rectangle mock_berry_output::bounds() const { return bounding_rect; }
}
}
