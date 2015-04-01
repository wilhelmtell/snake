#ifndef SNK_SDL_FACTORY_HH_
#define SNK_SDL_FACTORY_HH_

#include "abstract_factory.hh"
#include <memory>
#include "game_output.hh"
#include "snake_output.hh"
#include "snake_body_output.hh"
#include "snake_segment_output.hh"
#include "berry_output.hh"
#include "snake_direction_output.hh"
#include "score_output.hh"
#include "sdl_window.hh"
#include "sdl_renderer.hh"

namespace snk {
struct sdl_factory : abstract_factory {
  sdl_factory();

  std::unique_ptr<game_output> make_game_output() const override;
  std::unique_ptr<snake_output> make_snake_output() const override;
  std::unique_ptr<snake_body_output> make_snake_body_output() const override;
  std::unique_ptr<snake_segment_output> make_snake_segment_output()
    const override;
  std::unique_ptr<berry_output> make_berry_output() const override;
  std::unique_ptr<score_output> make_score_output() const override;
  std::unique_ptr<snake_direction_output> make_snake_direction_output()
    const override;

private:
  sdl_window window;
  sdl_renderer renderer;
};
}

#endif
