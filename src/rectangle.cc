#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(width w, height h)
: rectangle{position{0, 0}, std::move(w), std::move(h)} {}

rectangle::rectangle(position const& p, width w, height h)
: x{p.x}, y{p.y}, w{w.get()}, h{h.get()} {}
}
