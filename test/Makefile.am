check_PROGRAMS = check_snake
check_snake_SOURCES = berry.cc \
                      mock_score_output.hh mock_score_output.cc \
                      game.cc \
                      height.cc \
                      main.cc \
                      mock_berry_output.hh mock_berry_output.cc \
                      mock_factory.hh mock_factory.cc \
                      mock_game_output.hh mock_game_output.cc \
                      mock_snake_body_output.hh mock_snake_body_output.cc \
                      mock_snake_direction_output.hh mock_snake_direction_output.cc \
                      mock_snake_output.hh mock_snake_output.cc \
                      mock_snake_segment_output.hh mock_snake_segment_output.cc \
                      point_to_string.hh point_to_string.cc \
                      score.cc \
                      snake.cc \
                      snake_direction.cc \
                      width.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS} ${SDL2_TTF_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS} ${SDL2_TTF_LIBS}

check: check-am
	./$(check_PROGRAMS) --reporter=compact
