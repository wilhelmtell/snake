#ifndef SNK_TEST_MOCK_SNAKE_INPUT_HH_
#define SNK_TEST_MOCK_SNAKE_INPUT_HH_

#include "../src/snake_input.hh"
#include "../src/snake_control_fwd.hh"

namespace snk {
namespace test {
struct mock_snake_input : snk::snake_input {
  explicit mock_snake_input(snake_control* const control);

  void tick() override;

private:
  snake_control* control;
};
}
}

#endif
