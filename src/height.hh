#ifndef SNK_HEIGHT_HH_
#define SNK_HEIGHT_HH_

namespace snk {
struct height {
  using value_type = int;

  height() = default;
  explicit height(value_type value);

  value_type get() const;

private:
  value_type value;
};
}

#endif
