#ifndef SNK_SDL_HH_
#define SNK_SDL_HH_

namespace snk {
struct sdl {
  sdl();
  sdl(sdl const&) = delete;
  sdl& operator=(sdl const&) = delete;
  sdl(sdl&&);
  sdl& operator=(sdl&&);
  ~sdl();

private:
  bool owning;
};
}

#endif
