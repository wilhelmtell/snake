#include "mock_score_output.hh"
#include <functional>
#include <string>
#include "../src/width.hh"
#include "../src/height.hh"
#include "../src/rectangle.hh"

namespace snk {
namespace test {
void mock_score_output::draw_text(std::string const& /*text*/,
                                  unsigned char /*r*/,
                                  unsigned char /*g*/,
                                  unsigned char /*b*/,
                                  unsigned char /*a*/) {}

rectangle mock_score_output::bounds() const { return {}; }
}
}
