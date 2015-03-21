#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(position p, width w, height h)
: p{std::move(p)}, w{w.get()}, h{h.get()} {}

bool outside(position const& p, rectangle const& b) {
  return p.x < b.p.x || p.x > b.w || p.y < b.p.y || p.y > b.h;
}
}
