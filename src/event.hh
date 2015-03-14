#ifndef SNK_EVENT_HH_
#define SNK_EVENT_HH_

namespace snk {
struct event {
  enum type_t {
    unknown = -1,
    keydown_left,
    keydown_right,
    keydown_up,
    keydown_down,
    keydown_esc,
  };

  event(type_t const& t);

public:
  type_t type;
};
}

#endif
