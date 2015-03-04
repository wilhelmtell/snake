#ifndef SNK_TEST_QUIT_SNAKE_INPUT_HH_
#define SNK_TEST_QUIT_SNAKE_INPUT_HH_

#include "../src/snake_input.hh"
#include "../src/snake_control_fwd.hh"

namespace snk {
namespace test {
struct quit_snake_input : snk::snake_input {
  void controlled_by(snake_control* control) override;
  void tick() override;

private:
  snake_control* control;
};
}
}

#endif
