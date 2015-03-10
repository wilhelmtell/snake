#ifndef SNK_EVENT_HH_
#define SNK_EVENT_HH_

namespace snk {
struct event {
  enum type {
    unknown = -1,
    keydown_left,
    keydown_right,
    keydown_up,
    keydown_down,
  };

  explicit event(type const& t);

public:
  type t;
};
}

#endif
