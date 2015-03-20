#include "rectangle.hh"
#include "width.hh"
#include "height.hh"

namespace snk {
rectangle::rectangle(width w, height h) : w{w.get()}, h{h.get()} {}
}
