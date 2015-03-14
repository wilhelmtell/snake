#ifndef SNK_SDL_HH_
#define SNK_SDL_HH_

#include <memory>

namespace snk {
struct sdl {
  explicit sdl(int const& flags);
  sdl(sdl&& rhs);
  sdl& operator=(sdl&& rhs);
  sdl(sdl const& rhs) = delete;
  sdl& operator=(sdl const& rhs) = delete;
  ~sdl();

private:
  bool owning;
};
}

#endif
