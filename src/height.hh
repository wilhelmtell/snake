#ifndef SNK_HEIGHT_HH_
#define SNK_HEIGHT_HH_

namespace snk {
struct height {
  height() = default;
  height(int value);

  int get() const;

private:
  int value;
};
}

#endif
