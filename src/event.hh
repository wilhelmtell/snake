#ifndef SNK_EVENT_HH_
#define SNK_EVENT_HH_

namespace snk {
enum class event {
  unknown = -1,
  keydown_left,
  keydown_right,
  keydown_up,
  keydown_down,
  keydown_esc,
};
}

#endif
