#ifndef SNK_TEST_MOCK_FACTORY_HH_
#define SNK_TEST_MOCK_FACTORY_HH_

#include "../src/abstract_factory.hh"
#include <memory>
#include "../src/game_input.hh"
#include "../src/game_output.hh"
#include "../src/window_input.hh"
#include "../src/window_output.hh"

namespace snk {
namespace test {
struct mock_factory : snk::abstract_factory {
  std::unique_ptr<snk::game_input> make_game_input() const override;
  std::unique_ptr<snk::game_output> make_game_output() const override;
  std::unique_ptr<snk::window_input> make_window_input() const override;
  std::unique_ptr<snk::window_output> make_window_output() const override;
  std::unique_ptr<snk::snake_input> make_snake_input() const override;
  std::unique_ptr<snk::snake_output> make_snake_output() const override;
};
}
}

#endif
