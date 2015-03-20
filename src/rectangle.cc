#include "rectangle.hh"
#include <utility>
#include "width.hh"
#include "height.hh"
#include "position.hh"

namespace snk {
rectangle::rectangle(position p, width w, height h)
: p{std::move(p)}, w{w.get()}, h{h.get()} {}
}
