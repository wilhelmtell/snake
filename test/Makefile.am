check_PROGRAMS = check_snake
check_snake_SOURCES = berry.cc \
                      game.cc \
                      position_to_string.hh position_to_string.cc \
                      main.cc \
                      mock_berry_output.hh mock_berry_output.cc \
                      mock_factory.hh mock_factory.cc \
                      mock_game_output.hh mock_game_output.cc \
                      mock_snake_output.hh mock_snake_output.cc \
                      snake.cc \
                      window.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
