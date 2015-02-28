#include "game_control.hh"
#include "game_view.hh"
#include "window_view.hh"
#include "window_control.hh"

namespace snk {
game_control::game_control(game_view* view, window_view* w_v)
: view(view), w_v{w_v}, w_c{w_v} {}

void game_control::notify_end() { view = nullptr; }

bool game_control::is_on() const { return view != nullptr; }

void game_control::tick() { view->tick(); }
}
