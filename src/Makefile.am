SOURCE = main.c \
	malloc.c \
	pthread.c \
	regex.c \
	stdio.c \
	string.c \
	utf8.c \

LIBCBENCH_INCLUDES = -I${abs_top_srcdir}/src

AM_CPPFLAGS = ${LIBCBENCH_INCLUDES} ${LIBCBENCH_CPPFLAGS}

bin_PROGRAMS = libc-bench

libc_bench_LDFLAGS = -lpat
