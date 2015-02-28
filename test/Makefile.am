check_PROGRAMS = check_snake
check_snake_SOURCES = main.cc \
                      quit_game_view.hh quit_game_view.cc \
                      mock_game_view.hh mock_game_view.cc \
                      game.cc \
                      mock_berry_view.hh mock_berry_view.cc \
                      berry.cc \
                      mock_snake_view.hh mock_snake_view.cc \
                      snake.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
