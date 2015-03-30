#ifndef SNK_EVENT_DISPATCH_HH_
#define SNK_EVENT_DISPATCH_HH_

#include <boost/signals2/signal.hpp>
#include "point_fwd.hh"

namespace snk {
struct event_dispatch {
  using connection = boost::signals2::connection;
  template <typename Op>
  using signal = boost::signals2::signal<Op>;

  using quit_signal_t = signal<void()>;
  using quit_slot_t = quit_signal_t::slot_type;
  using keydown_left_signal_t = signal<void()>;
  using keydown_left_slot_t = keydown_left_signal_t::slot_type;
  using keydown_right_signal_t = signal<void()>;
  using keydown_right_slot_t = keydown_right_signal_t::slot_type;
  using keydown_up_signal_t = signal<void()>;
  using keydown_up_slot_t = keydown_up_signal_t::slot_type;
  using keydown_down_signal_t = signal<void()>;
  using keydown_down_slot_t = keydown_down_signal_t::slot_type;
  using keydown_esc_signal_t = signal<void()>;
  using keydown_esc_slot_t = keydown_esc_signal_t::slot_type;
  using berry_eaten_signal_t = signal<void(point const& position)>;
  using berry_eaten_slot_t = berry_eaten_signal_t::slot_type;
  using berry_spawned_signal_t = signal<void(point const& position)>;
  using berry_spawned_slot_t = berry_spawned_signal_t::slot_type;
  using pause_game_signal_t = signal<void()>;
  using pause_game_slot_t = pause_game_signal_t::slot_type;
  using resume_game_signal_t = signal<void()>;
  using resume_game_slot_t = resume_game_signal_t::slot_type;
  using keydown_p_signal_t = signal<void()>;
  using keydown_p_slot_t = keydown_p_signal_t::slot_type;
  using keydown_return_signal_t = signal<void()>;
  using keydown_return_slot_t = keydown_return_signal_t::slot_type;
  using game_restarted_signal_t = signal<void()>;
  using game_restarted_slot_t = game_restarted_signal_t::slot_type;

  void quit() const;
  connection on_quit(quit_signal_t::slot_type const& op);
  void keydown_esc() const;
  connection on_keydown_esc(keydown_esc_slot_t const& op);
  void keydown_p() const;
  connection on_keydown_p(keydown_p_slot_t const& op);
  void keydown_left() const;
  connection on_keydown_left(keydown_left_slot_t const& op);
  void keydown_right() const;
  connection on_keydown_right(keydown_right_slot_t const& op);
  void keydown_up() const;
  connection on_keydown_up(keydown_up_slot_t const& op);
  void keydown_down() const;
  connection on_keydown_down(keydown_down_slot_t const& op);
  void berry_eaten(point const& position) const;
  connection on_berry_eaten(berry_eaten_slot_t const& op);
  void berry_spawned(point const& position) const;
  connection on_berry_spawned(berry_spawned_slot_t const& op);
  void pause_game() const;
  connection on_pause_game(pause_game_slot_t const& op);
  void resume_game() const;
  connection on_resume_game(resume_game_slot_t const& op);
  void keydown_return() const;
  connection on_keydown_return(keydown_return_slot_t const& op);
  void game_restarted() const;
  connection on_game_restarted(game_restarted_slot_t const& op);

private:
  quit_signal_t quit_signal;
  keydown_esc_signal_t keydown_esc_signal;
  keydown_p_signal_t keydown_p_signal;
  keydown_left_signal_t keydown_left_signal;
  keydown_right_signal_t keydown_right_signal;
  keydown_up_signal_t keydown_up_signal;
  keydown_down_signal_t keydown_down_signal;
  berry_eaten_signal_t berry_eaten_signal;
  berry_spawned_signal_t berry_spawned_signal;
  pause_game_signal_t pause_game_signal;
  resume_game_signal_t resume_game_signal;
  keydown_return_signal_t keydown_return_signal;
  game_restarted_signal_t game_restarted_signal;
};
}

#endif
