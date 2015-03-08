#ifndef SNK_TEST_MOCK_WINDOW_INPUT_HH_
#define SNK_TEST_MOCK_WINDOW_INPUT_HH_

#include "../src/window_input.hh"
#include "../src/window_control_fwd.hh"

namespace snk {
namespace test {
struct mock_window_input : snk::window_input {
  explicit mock_window_input(snk::window_control* const control);

  void tick() override;

private:
  window_control* control;
};
}
}

#endif
