#include "sdl_ttf_font_open_error.hh"
#include <stdexcept>

namespace snk {
sdl_ttf_font_open_error::sdl_ttf_font_open_error(char const* const m)
: std::runtime_error{m} {}
}
