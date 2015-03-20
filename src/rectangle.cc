#include "rectangle.hh"
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(position const& p, width w, height h)
: x{p.x}, y{p.y}, w{w.get()}, h{h.get()} {}
}
