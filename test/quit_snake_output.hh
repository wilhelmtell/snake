#ifndef SNK_TEST_QUIT_SNAKE_OUTPUT_HH_
#define SNK_TEST_QUIT_SNAKE_OUTPUT_HH_

#include "../src/snake_output.hh"

namespace snk {
namespace test {
struct quit_snake_output : snk::snake_output {
  void position(int, int) override;
};
}
}

#endif
