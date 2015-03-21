#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(position p, width w, height h)
: p{std::move(p)}, w{w.get()}, h{h.get()} {}

bool intersect(rectangle const& a, rectangle const& b) {
  return !outside(a.p, b) || !outside(position{a.w, a.h}, b);
}
}
