# ============================================================================
#  http://www.gnu.org/software/autoconf-archive/ax_cxx_compile_stdcxx_14.html
# ============================================================================
#
# SYNOPSIS
#
#   AX_CXX_COMPILE_STDCXX_14([ext|noext],[mandatory|optional])
#
# DESCRIPTION
#
#   Check for baseline language coverage in the compiler for the C++14
#   standard; if necessary, add switches to CXXFLAGS to enable support.
#
#   The first argument, if specified, indicates whether you insist on an
#   extended mode (e.g. -std=gnu++14) or a strict conformance mode (e.g.
#   -std=c++14).  If neither is specified, you get whatever works, with
#   preference for an extended mode.
#
#   The second argument, if specified 'mandatory' or if left unspecified,
#   indicates that baseline C++14 support is required and that the macro
#   should error out if no mode with that support is found.  If specified
#   'optional', then configuration proceeds regardless, after defining
#   HAVE_CXX14 if and only if a supporting mode is found.
#
#   Based on am_cxx_compile_stdcxx_11.m4.
#
# LICENSE
#
#   Copyright (c) 2008 Benjamin Kosnik <bkoz@redhat.com>
#   Copyright (c) 2012 Zack Weinberg <zackw@panix.com>
#   Copyright (c) 2013 Roy Stogner <roystgnr@ices.utexas.edu>
#   Copyright (c) 2014, 2015 Google Inc.; contributed by Alexey Sokolov <sokolov@google.com>
#
#   Copying and distribution of this file, with or without modification, are
#   permitted in any medium without royalty provided the copyright notice
#   and this notice are preserved. This file is offered as-is, without any
#   warranty.

#serial 9

m4_define([_AX_CXX_COMPILE_STDCXX_14_testbody], [[
  int main() {static_assert(__cplusplus >= 201402L, "C++14 compliance check");}
]])

AC_DEFUN([AX_CXX_COMPILE_STDCXX_14], [dnl
  m4_if([$1], [], [],
        [$1], [ext], [],
        [$1], [noext], [],
        [m4_fatal([invalid argument `$1' to AX_CXX_COMPILE_STDCXX_14])])dnl
  m4_if([$2], [], [ax_cxx_compile_cxx14_required=true],
        [$2], [mandatory], [ax_cxx_compile_cxx14_required=true],
        [$2], [optional], [ax_cxx_compile_cxx14_required=false],
        [m4_fatal([invalid second argument `$2' to AX_CXX_COMPILE_STDCXX_14])])
  AC_LANG_PUSH([C++])dnl
  ac_success=no
  AC_CACHE_CHECK(whether $CXX compiles C++14 by default,
  ax_cv_cxx_compile_cxx14,
  [AC_COMPILE_IFELSE([AC_LANG_SOURCE([_AX_CXX_COMPILE_STDCXX_14_testbody])],
    [ax_cv_cxx_compile_cxx14=yes],
    [ax_cv_cxx_compile_cxx14=no])])
  if test x$ax_cv_cxx_compile_cxx14 = xyes; then
    ac_success=yes
  fi

  m4_if([$1], [noext], [], [dnl
  if test x$ac_success = xno; then
    for switch in -std=gnu++14 -std=gnu++1y; do
      cachevar=AS_TR_SH([ax_cv_cxx_compile_cxx14_$switch])
      AC_CACHE_CHECK(whether $CXX supports C++14 features with $switch,
                     $cachevar,
        [ac_save_CXXFLAGS="$CXXFLAGS"
         CXXFLAGS="$CXXFLAGS $switch"
         AC_COMPILE_IFELSE([AC_LANG_SOURCE([_AX_CXX_COMPILE_STDCXX_14_testbody])],
          [eval $cachevar=yes],
          [eval $cachevar=no])
         CXXFLAGS="$ac_save_CXXFLAGS"])
      if eval test x\$$cachevar = xyes; then
        CXXFLAGS="$CXXFLAGS $switch"
        ac_success=yes
        break
      fi
    done
  fi])

  m4_if([$1], [ext], [], [dnl
  if test x$ac_success = xno; then
    for switch in -std=c++14 -std=c++1y; do
      cachevar=AS_TR_SH([ax_cv_cxx_compile_cxx14_$switch])
      AC_CACHE_CHECK(whether $CXX supports C++14 features with $switch,
                     $cachevar,
        [ac_save_CXXFLAGS="$CXXFLAGS"
         CXXFLAGS="$CXXFLAGS $switch"
         AC_COMPILE_IFELSE([AC_LANG_SOURCE([_AX_CXX_COMPILE_STDCXX_14_testbody])],
          [eval $cachevar=yes],
          [eval $cachevar=no])
         CXXFLAGS="$ac_save_CXXFLAGS"])
      if eval test x\$$cachevar = xyes; then
        CXXFLAGS="$CXXFLAGS $switch"
        ac_success=yes
        break
      fi
    done
  fi])
  AC_LANG_POP([C++])
  if test x$ax_cxx_compile_cxx14_required = xtrue; then
    if test x$ac_success = xno; then
      AC_MSG_ERROR([*** A C++14 compiler is required.])
    fi
  else
    if test x$ac_success = xno; then
      HAVE_CXX14=0
      AC_MSG_NOTICE([No C++14 compiler was found])
    else
      HAVE_CXX14=1
      AC_DEFINE(HAVE_CXX14,1,
                [define if the compiler supports C++14])
    fi

    AC_SUBST(HAVE_CXX14)
  fi
])
