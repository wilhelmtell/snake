bin_PROGRAMS = snake
snake_SOURCES = main.cc
snake_LDADD = libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

noinst_LIBRARIES = libsnake.a
libsnake_a_SOURCES = sdl.hh sdl.cc \
                     snake_output_fwd.hh \
                     snake_output.hh \
                     sdl_snake_output.hh sdl_snake_output.cc \
                     snake_control.hh snake_control.cc \
                     snake.hh snake.cc \
                     berry_output_fwd.hh \
                     berry_output.hh \
                     sdl_berry_output.hh sdl_berry_output.cc \
                     berry_control.hh berry_control.cc \
                     berry.hh berry.cc \
                     window_input_fwd.hh \
                     window_input.hh \
                     sdl_window_input.hh sdl_window_input.cc \
                     window_output_fwd.hh \
                     window_output.hh \
                     window_control_fwd.hh \
                     window_control.hh window_control.cc \
                     sdl_window_output.hh sdl_window_output.cc \
                     sdl_window_handle_fwd.hh \
                     sdl_window_handle.hh sdl_window_handle.cc \
                     window.hh window.cc \
                     window_creation_error.hh window_creation_error.cc \
                     renderer_output_fwd.hh \
                     renderer_output.hh \
                     renderer_control.hh renderer_control.cc \
                     sdl_renderer_output.hh sdl_renderer_output.cc \
                     renderer_fwd.hh \
                     sdl_renderer_handle.hh sdl_renderer_handle.cc \
                     renderer.hh renderer.cc \
                     renderer_creation_error.hh renderer_creation_error.cc \
                     game_fwd.hh \
                     sdl_game_input.hh sdl_game_input.cc \
                     game_input_fwd.hh \
                     game_input.hh \
                     game_output_fwd.hh \
                     game_output.hh \
                     sdl_game_output.hh sdl_game_output.cc \
                     game_control_fwd.hh \
                     game_control.hh game_control.cc \
                     game.hh game.cc
