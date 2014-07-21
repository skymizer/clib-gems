#!/bin/bash
#                       The libc-bench Project
#
#  This file is distributed under the GPLv2
#  See LICENSE for details.
#
# Luba Tang <luba@skymizer.com>
# GGM Kuo <ggm@skymizer.com>

function build
{
  local VERSION=$1
  local CONFIG=$2
  local BUILDDIR=${VERSION}/../build-$(basename $VERSION)-${CONFIG}

  if [ -d ${BUILDDIR} ]; then
    rm -rf ${BUILDDIR}
  fi

  mkdir ${BUILDDIR}
  cd ${BUILDDIR}
  ${VERSION}/autogen.sh

  if [ "${CONFIG}" = "dbg" ]; then
    ${VERSION}/configure --prefix=${HOME}/SysRoot --enable-unittest
  elif [ "${CONFIG}" = "opt" ]; then
    ${VERSION}/configure --prefix=${HOME}/SysRoot --enable-optimize
  else
    ${VERSION}/configure --prefix=${HOME}/SysRoot
  fi

  make all install

  cd -
}

if [ $# != 2 ] && [ $# != 1 ]; then
  echo "Usage: $0 [source folder] [dbg|opt|normal]"
  exit 1;
fi

# Check if $1 is absolute or relative path.
if [[ "$1" = /* ]]; then
  SRCDIR=$1
else
  SRCDIR=`pwd`/$1
fi

TRGDIR=$2

if [ -z "${TRGDIR}" ]; then
  TRGDIR="normal"
fi

if [ "${TRGDIR}" != "dbg" ] && [ "${TRGDIR}" != "opt" ] && [ "${TRGDIR}" != "normal" ]; then
  echo "Usage: $0 [source folder] [dbg|opt|normal]"
  exit 1;
fi

build ${SRCDIR} ${TRGDIR}
