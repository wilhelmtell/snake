#include "event_dispatch.hh"

namespace snk {
void event_dispatch::quit() const { quit_signal(); }

event_dispatch::connection event_dispatch::on_quit(
  quit_signal_t::slot_type const& op) {
  return quit_signal.connect(op);
}

void event_dispatch::keydown_esc() const { keydown_esc_signal(); }

event_dispatch::connection event_dispatch::on_keydown_esc(
  keydown_esc_slot_t const& op) {
  return keydown_esc_signal.connect(op);
}

void event_dispatch::keydown_p() const { keydown_p_signal(); }

event_dispatch::connection event_dispatch::on_keydown_p(
  keydown_p_slot_t const& op) {
  return keydown_p_signal.connect(op);
}

void event_dispatch::keydown_left() const { keydown_left_signal(); }

event_dispatch::connection event_dispatch::on_keydown_left(
  keydown_left_slot_t const& op) {
  return keydown_left_signal.connect(op);
}

void event_dispatch::keydown_right() const { keydown_right_signal(); }

event_dispatch::connection event_dispatch::on_keydown_right(
  keydown_right_slot_t const& op) {
  return keydown_right_signal.connect(op);
}

void event_dispatch::keydown_up() const { keydown_up_signal(); }

event_dispatch::connection event_dispatch::on_keydown_up(
  keydown_up_slot_t const& op) {
  return keydown_up_signal.connect(op);
}

void event_dispatch::keydown_down() const { keydown_down_signal(); }

event_dispatch::connection event_dispatch::on_keydown_down(
  keydown_down_slot_t const& op) {
  return keydown_down_signal.connect(op);
}

void event_dispatch::berry_eaten(point const& position) const {
  berry_eaten_signal(position);
}

event_dispatch::connection event_dispatch::on_berry_eaten(
  berry_eaten_slot_t const& op) {
  return berry_eaten_signal.connect(op);
}

void event_dispatch::berry_spawned(point const& position) const {
  berry_spawned_signal(position);
}

event_dispatch::connection event_dispatch::on_berry_spawned(
  berry_spawned_slot_t const& op) {
  return berry_spawned_signal.connect(op);
}

void event_dispatch::keydown_return() const { keydown_return_signal(); }

event_dispatch::connection event_dispatch::on_keydown_return(
  keydown_return_slot_t const& op) {
  return keydown_return_signal.connect(op);
}

void event_dispatch::toggle_pause() const { toggle_pause_signal(); }

event_dispatch::connection event_dispatch::on_toggle_pause(
  toggle_pause_slot_t const& op) {
  return toggle_pause_signal.connect(op);
}

void event_dispatch::game_paused() const { game_paused_signal(); }

event_dispatch::connection event_dispatch::on_game_paused(
  game_paused_slot_t const& op) {
  return game_paused_signal.connect(op);
}

void event_dispatch::game_resumed() const { game_resumed_signal(); }

event_dispatch::connection event_dispatch::on_game_resumed(
  game_resumed_slot_t const& op) {
  return game_resumed_signal.connect(op);
}

void event_dispatch::restart() const { restart_signal(); }

event_dispatch::connection event_dispatch::on_restart(
  restart_slot_t const& op) {
  return restart_signal.connect(op);
}
}
