#ifndef SNK_ABSTRACT_FACTORY_HH_
#define SNK_ABSTRACT_FACTORY_HH_

#include <memory>
#include "game_control_fwd.hh"
#include "game_output_fwd.hh"
#include "window_control_fwd.hh"
#include "window_output_fwd.hh"
#include "snake_control_fwd.hh"
#include "snake_output_fwd.hh"

namespace snk {
struct abstract_factory {
  virtual ~abstract_factory(){};
  virtual std::unique_ptr<game_output> make_game_output() const = 0;
  virtual std::unique_ptr<window_output> make_window_output() const = 0;
  virtual std::unique_ptr<snake_output> make_snake_output() const = 0;
};
}

#endif
