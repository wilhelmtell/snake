#ifndef SNK_TEST_QUIT_SNAKE_INPUT_HH_
#define SNK_TEST_QUIT_SNAKE_INPUT_HH_

#include "../src/snake_input.hh"
#include "../src/snake_control_fwd.hh"

namespace snk {
namespace test {
struct quit_snake_input : snk::snake_input {
  explicit quit_snake_input(snake_control* const control);
};
}
}

#endif
