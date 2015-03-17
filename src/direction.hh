#ifndef SNK_DIRECTION_HH_
#define SNK_DIRECTION_HH_

namespace snk {
struct direction {
  enum type_t { up, right, down, left };

  direction() = default;
  direction(type_t const& type);

public:
  type_t type;
};

bool operator==(direction const& lhs, direction const& rhs);
bool operator!=(direction const& lhs, direction const& rhs);
}

#endif
