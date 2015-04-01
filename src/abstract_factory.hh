#ifndef SNK_ABSTRACT_FACTORY_HH_
#define SNK_ABSTRACT_FACTORY_HH_

#include <memory>
#include "game_output_fwd.hh"
#include "snake_output_fwd.hh"
#include "snake_body_output_fwd.hh"
#include "snake_segment_output_fwd.hh"
#include "berry_output_fwd.hh"
#include "snake_direction_output_fwd.hh"

namespace snk {
struct abstract_factory {
  virtual ~abstract_factory(){};
  virtual std::unique_ptr<game_output> make_game_output() const = 0;
  virtual std::unique_ptr<snake_output> make_snake_output() const = 0;
  virtual std::unique_ptr<snake_body_output> make_snake_body_output()
    const = 0;
  virtual std::unique_ptr<snake_segment_output> make_snake_segment_output()
    const = 0;
  virtual std::unique_ptr<berry_output> make_berry_output() const = 0;
  virtual std::unique_ptr<snake_direction_output> make_snake_direction_output()
    const = 0;
};
}

#endif
