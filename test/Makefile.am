check_PROGRAMS = check_snake
check_snake_SOURCES = dummy.cc main.cc
check_snake_LDADD = ../src/libsnake.a
AM_CPPFLAGS = ${BOOST_CPPFLAGS}
AM_LDFLAGS = ${BOOST_LDFLAGS} \
             ${BOOST_FILESYSTEM_LIB} \
             ${BOOST_SYSTEM_LIB}

check: check-am
	./$(check_PROGRAMS)
