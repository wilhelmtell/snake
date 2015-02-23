#ifndef SNK_WINDOW_HH_
#define SNK_WINDOW_HH_

struct SDL_Window;

namespace snk {
extern int const WINDOW_W;
extern int const WINDOW_H;

struct window {
  window();
  window(window const&) = delete;
  window& operator=(window const&) = delete;
  window(window&& rhs);
  window& operator=(window&& rhs);
  ~window();

  SDL_Window* get() const;

private:
  SDL_Window* w;
};
}

#endif
