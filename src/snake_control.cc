#include "snake_control.hh"
#include "snake_output.hh"

namespace snk {
snake_control::snake_control(snake_output* output) { output->position(0, 0); }
}
