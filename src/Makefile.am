bin_PROGRAMS = snake
snake_SOURCES = main.cc
snake_LDADD = libsnake.a
AM_CXXFLAGS = -std=c++14 ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

noinst_LIBRARIES = libsnake.a
libsnake_a_SOURCES = dummy.cc dummy.hh \
                     sdl.hh sdl.cc
