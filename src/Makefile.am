bin_PROGRAMS = snake
snake_SOURCES = main.cc
snake_LDADD = libsnake.a
AM_CXXFLAGS = ${SDL2_CFLAGS}
AM_LDFLAGS = ${SDL2_LIBS}

noinst_LIBRARIES = libsnake.a
libsnake_a_SOURCES = abstract_factory.hh \
                     abstract_factory_fwd.hh \
                     berry_control.hh berry_control.cc \
                     berry_output.hh \
                     berry_output_fwd.hh \
                     event.hh event.cc \
                     event_fwd.hh \
                     game_control.hh game_control.cc \
                     game_control_fwd.hh \
                     game_output.hh \
                     game_output_fwd.hh \
                     renderer_creation_error.hh renderer_creation_error.cc \
                     sdl_berry_output.hh sdl_berry_output.cc \
                     sdl_event_to_event.hh sdl_event_to_event.cc \
                     sdl_factory.hh sdl_factory.cc \
                     sdl_game_output.hh sdl_game_output.cc \
                     sdl_renderer.hh sdl_renderer.cc \
                     sdl_snake_output.hh sdl_snake_output.cc \
                     sdl_window_handle.hh sdl_window_handle.cc \
                     sdl_window_handle_fwd.hh \
                     sdl_window_output.hh sdl_window_output.cc \
                     snake_control.hh snake_control.cc \
                     snake_control_fwd.hh \
                     snake_output.hh \
                     snake_output_fwd.hh \
                     window_control.hh window_control.cc \
                     window_control_fwd.hh \
                     window_creation_error.hh window_creation_error.cc \
                     window_output.hh \
                     window_output_fwd.hh
