#!/bin/sh
##############################################################################
#
#                       Skymizer (TM) Configuration
#
# Copyright (C), 2013, Skymizer Inc.. GPLv2.
##############################################################################

LIBTOOLIZE=libtoolize
my_uname=`uname`

if [ ${my_uname} = "Darwin" ]; then
  LIBTOOLIZE=glibtoolize
fi
root=`dirname $0`
cd $root

aclocal -I ./m4
autoheader
${LIBTOOLIZE} --force
automake --add-missing
autoconf
