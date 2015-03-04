check_PROGRAMS = check_snake
check_snake_SOURCES = berry.cc \
                      game.cc \
                      main.cc \
                      mock_berry_output.hh mock_berry_output.cc \
                      mock_factory.hh mock_factory.cc \
                      mock_game_input.hh mock_game_input.cc \
                      mock_game_output.hh mock_game_output.cc \
                      mock_renderer_output.hh mock_renderer_output.cc \
                      mock_snake_input.hh mock_snake_input.cc \
                      mock_snake_output.hh mock_snake_output.cc \
                      mock_window_input.hh mock_window_input.cc \
                      mock_window_output.hh mock_window_output.cc \
                      noop_game_input.hh noop_game_input.cc \
                      noop_game_output.hh noop_game_output.cc \
                      quit_factory.hh quit_factory.cc \
                      quit_game_input.hh quit_game_input.cc \
                      quit_game_output.hh quit_game_output.cc \
                      quit_snake_input.hh quit_snake_input.cc \
                      quit_snake_output.hh quit_snake_output.cc \
                      quit_window_input.hh quit_window_input.cc \
                      quit_window_output.hh quit_window_output.cc \
                      renderer.cc \
                      snake.cc \
                      window.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
