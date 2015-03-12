#ifndef SNK_RENDERER_CREATION_ERROR_HH_
#define SNK_RENDERER_CREATION_ERROR_HH_

#include <stdexcept>

namespace snk {
struct renderer_creation_error : std::runtime_error {
  renderer_creation_error(char const* const m);
};
}

#endif
