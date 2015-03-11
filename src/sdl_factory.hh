#ifndef SNK_SDL_FACTORY_HH_
#define SNK_SDL_FACTORY_HH_

#include "abstract_factory.hh"
#include <memory>
#include "game_output.hh"
#include "window_output.hh"
#include "snake_output.hh"

namespace snk {
struct sdl_factory : abstract_factory {
  std::unique_ptr<game_output> make_game_output() const override;
  std::unique_ptr<window_output> make_window_output() const override;
  std::unique_ptr<snake_output> make_snake_output() const override;
};
}

#endif
