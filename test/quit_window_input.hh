#ifndef SNK_TEST_QUIT_WINDOW_INPUT_HH_
#define SNK_TEST_QUIT_WINDOW_INPUT_HH_

#include "../src/window_input.hh"
#include "../src/window_control_fwd.hh"

namespace snk {
namespace test {
struct quit_window_input : snk::window_input {
  void controlled_by(snk::window_control* control) override;
  void tick() override;

private:
  window_control* control;
};
}
}

#endif
