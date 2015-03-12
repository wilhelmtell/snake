#ifndef SNK_GAME_OUTPUT_HH_
#define SNK_GAME_OUTPUT_HH_

namespace snk {
struct game_output {
  virtual ~game_output() {}

  virtual void present() = 0;
};
}

#endif
