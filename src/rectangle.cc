#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "point.hh"

namespace snk {
rectangle::rectangle(point p, width w, height h)
: p{std::move(p)}, w{w}, h{h} {}

bool intersect(rectangle const& a, rectangle const& b) {
  return outside(a.p, b) || outside(point{a.w, a.h}, b);
}

bool outside(rectangle const& a, rectangle const& b) {
  return outside(a.p, b) || outside(point{a.p.x + a.w, a.p.y + a.h}, b);
}

point bottom_right(rectangle const& r) {
  return point{r.p.x + r.w, r.p.y + r.h};
}
}
