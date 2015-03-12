#ifndef SNK_RENDERER_INPUT_HH_
#define SNK_RENDERER_INPUT_HH_

namespace snk {
struct renderer_input {
  virtual ~renderer_input() {}
  virtual input() = 0;
};
}

#endif
