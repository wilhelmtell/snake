#ifndef SNK_WINDOW_CREATION_ERROR_HH_
#define SNK_WINDOW_CREATION_ERROR_HH_

#include <stdexcept>

namespace snk {
struct window_creation_error : std::runtime_error {
  window_creation_error() = default;
  window_creation_error(char const* const m);
};
}

#endif
