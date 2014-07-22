##############################################################################
#
#                       Skymizer (TM) Configuration
#
# Copyright (C), 2013, Skymizer Inc.. GPLv2.
##############################################################################

dnl AC_INIT(PKG_NAME, BUILD_VERSION, BUG_REPORTER)
AC_INIT([libc-bench],[copycat],[little.sky@skymizer.com])
AC_PREREQ(2.59)

AC_CONFIG_SRCDIR([LICENSE])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([m4])

####################
#  Check environments - `host`, `target` and `build`
CHECK_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([1.9 dist-bzip2 foreign subdir-objects])

####################
#  Languages
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])
LT_INIT

####################
# OUTPUT
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])

AC_OUTPUT
