#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(width w, height h)
: rectangle{std::move(w), std::move(h), position{0, 0}} {}

rectangle::rectangle(width w, height h, position const& p)
: w{w.get()}, h{h.get()}, x{p.x}, y{p.y} {}
}
