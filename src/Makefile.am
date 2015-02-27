bin_PROGRAMS = snake
snake_SOURCES = main.cc
snake_LDADD = libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

noinst_LIBRARIES = libsnake.a
libsnake_a_SOURCES = sdl.hh sdl.cc \
                     snake.hh snake.cc \
                     berry.hh berry.cc \
                     window.hh window.cc \
                     window_creation_error.hh window_creation_error.cc \
                     renderer_fwd.hh \
                     renderer.hh renderer.cc \
                     renderer_creation_error.hh renderer_creation_error.cc \
                     game_fwd.hh \
                     game.hh game.cc
