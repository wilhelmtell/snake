bin_PROGRAMS = snake
snake_SOURCES = main.cc
snake_LDADD = libsnake.a
AM_CPPFLAGS = ${BOOST_CPPFLAGS}
AM_LDFLAGS = ${BOOST_LDFLAGS} \
             ${BOOST_FILESYSTEM_LIB} \
             ${BOOST_SYSTEM_LIB}

noinst_LIBRARIES = libsnake.a
libsnake_a_SOURCES = dummy.cc dummy.hh
