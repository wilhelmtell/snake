check_PROGRAMS = check_snake
check_snake_SOURCES = main.cc \
                      mock_game_view.hh \
                      game.cc \
                      mock_snake_view.hh mock_snake_view.cc \
                      snake.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
