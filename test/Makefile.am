check_PROGRAMS = check_snake
check_snake_SOURCES = dummy.cc main.cc
check_snake_LDADD = ../src/libsnake.a
AM_CXXFLAGS = -std=c++14 ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

check: check-am
	./$(check_PROGRAMS)
