check_PROGRAMS = check_snake
check_snake_SOURCES = main.cc \
                      mock_window_input.hh mock_window_input.cc \
                      mock_window_output.hh \
                      window.cc \
                      noop_game_input.hh noop_game_input.cc \
                      quit_game_input.hh quit_game_input.cc \
                      quit_game_output.hh quit_game_output.cc \
                      noop_game_output.hh noop_game_output.cc \
                      game.cc \
                      mock_renderer_output.hh \
                      renderer.cc \
                      mock_berry_output.hh mock_berry_output.cc \
                      berry.cc \
                      mock_snake_output.hh mock_snake_output.cc \
                      snake.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
