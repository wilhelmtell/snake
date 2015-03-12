#ifndef SNK_GAME_INPUT_HH_
#define SNK_GAME_INPUT_HH_

namespace snk {
struct game_input {
  virtual ~game_input() {}
  virtual void tick() = 0;
};
}

#endif
