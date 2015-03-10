#ifndef SNK_TEST_QUIT_WINDOW_INPUT_HH_
#define SNK_TEST_QUIT_WINDOW_INPUT_HH_

#include "../src/window_input.hh"
#include "../src/window_control_fwd.hh"

namespace snk {
namespace test {
struct quit_window_input : snk::window_input {
  explicit quit_window_input(snk::window_control* const control);

  void tick() override;
};
}
}

#endif
