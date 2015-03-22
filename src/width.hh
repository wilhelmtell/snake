#ifndef SNK_WIDTH_HH_
#define SNK_WIDTH_HH_

namespace snk {
struct width {
  width() = default;
  explicit width(int value);

  int get() const;

private:
  int value;
};
}

#endif
