#include "mock_game_output.hh"
#include "rectangle.hh"
#include <utility>
#include "height.hh"
#include "width.hh"
#include <string>
#include <functional>

namespace snk {
namespace test {
mock_game_output::mock_game_output(rectangle bounds)
: bounding_rect{std::move(bounds)} {}

void mock_game_output::draw_text(
  std::string const& /*text*/,
  unsigned char /*r*/,
  unsigned char /*g*/,
  unsigned char /*b*/,
  unsigned char /*a*/,
  std::function<rectangle(width const&, height const&)>
  /*bounding_box*/) {}

void mock_game_output::clear(int /*r*/, int /*g*/, int /*b*/, int /*a*/) {}

void mock_game_output::present() {}

rectangle mock_game_output::bounds() const { return bounding_rect; }
}
}
