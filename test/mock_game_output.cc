#include "mock_game_output.hh"
#include "rectangle.hh"
#include <utility>

namespace snk {
namespace test {
mock_game_output::mock_game_output(rectangle bounds)
: bounding_rect{std::move(bounds)} {}

void mock_game_output::clear(int /*r*/, int /*g*/, int /*b*/, int /*a*/) {}

void mock_game_output::present() {}

rectangle mock_game_output::bounds() const { return bounding_rect; }
}
}
