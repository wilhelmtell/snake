AC_INIT([snake], m4_esyscmd_s([git describe --dirty 2>/dev/null || echo v0.1]), [matan.nassau@gmail.com])
AM_INIT_AUTOMAKE([1.14.1 foreign -Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_14([noext],[mandatory])
AC_PROG_RANLIB
AM_PROG_AR
PKG_CHECK_MODULES([SDL2], [sdl2 >= 2.0.3])
PKG_CHECK_MODULES([SDL2_TTF], [SDL2_ttf >= 2.0.12])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
