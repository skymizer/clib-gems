#===- portme.mak --------------------------------------------------------===#
#
#                       The Libc-Bench Project
#
#  This file is distributed under the GPLv2 License.
#  See LICENSE for details.
#
#===---------------------------------------------------------------------===#
# Toolchain
#===---------------------------------------------------------------------===#
CC      = gcc
CXX     = g++
AR      = ar rcs

#===---------------------------------------------------------------------===#
# Flags
#===---------------------------------------------------------------------===#
CFLAGS    = -O2 -g
CXXFLAGS  = -O2 -g -fpermissive
LDFLAGS   =
XCFLAGS   =
XCXXFLAGS =
XLDFLAGS  =
