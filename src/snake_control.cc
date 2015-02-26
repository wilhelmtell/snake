#include "snake_control.hh"
#include "snake_view.hh"

namespace snk {
snake_control::snake_control(snake_view* view) {
  view->position(0, 0);
}
}
