check_PROGRAMS = check_snake
check_snake_SOURCES = main.cc \
                      mock_window_view.hh \
                      window.cc \
                      quit_game_view.hh quit_game_view.cc \
                      noop_game_view.hh noop_game_view.cc \
                      game.cc \
                      mock_renderer_view.hh \
                      renderer.cc \
                      mock_berry_view.hh mock_berry_view.cc \
                      berry.cc \
                      mock_snake_view.hh mock_snake_view.cc \
                      snake.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
