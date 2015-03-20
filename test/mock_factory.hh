#ifndef SNK_TEST_MOCK_FACTORY_HH_
#define SNK_TEST_MOCK_FACTORY_HH_

#include "../src/abstract_factory.hh"
#include <memory>
#include "../src/game_output.hh"
#include "../src/snake_output.hh"
#include "../src/snake_body_output.hh"
#include "../src/snake_segment_output.hh"
#include "../src/berry_output.hh"

namespace snk {
namespace test {
struct mock_factory : snk::abstract_factory {
  std::unique_ptr<snk::game_output> make_game_output() const override;
  std::unique_ptr<snk::snake_output> make_snake_output() const override;
  std::unique_ptr<snake_body_output> make_snake_body_output() const override;
  std::unique_ptr<snake_segment_output> make_snake_segment_output()
    const override;
  std::unique_ptr<snk::berry_output> make_berry_output() const override;
};
}
}

#endif
