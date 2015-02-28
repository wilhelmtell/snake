#include "game_control.hh"
#include "game_view.hh"

namespace snk {
game_control::game_control(game_view* view) : view(view) {}

void game_control::notify_end() { view = nullptr; }

bool game_control::is_on() const { return view != nullptr; }

void game_control::tick() { view->tick(); }
}
