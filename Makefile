CC = arm-linux-gnueabihf-gcc-4.7
EGLIBC=/root/eglibc/eglibc/eglibc-2.17
CFLAGS = -c \
	-std=gnu99 \
	-fgnu89-inline \
	-fno-stack-protector \
	-O2 \
	-Winline \
	-Wwrite-strings \
	-fmerge-all-constants \
	-frounding-math \
	-fstrict-aliasing \
	-g \
	-pipe \
	-U_FORTIFY_SOURCE \
	-isystem $(EGLIBC)/debian/include \
	-I$(EGLIBC)/include \
	-I$(EGLIBC)/build-tree/armhf-libc \
	-I$(EGLIBC)/ports/sysdeps/unix/sysv/linux/arm/nptl \
	-I$(EGLIBC)/ports/sysdeps/unix/sysv/linux/arm \
	-I$(EGLIBC)/ports/sysdeps/unix/sysv/linux \
	-I$(EGLIBC)/nptl/sysdeps/unix/sysv/linux \
	-I$(EGLIBC)/nptl/sysdeps/pthread \
	-I$(EGLIBC)/sysdeps/pthread \
	-I$(EGLIBC)/sysdeps/unix/sysv/linux \
	-I$(EGLIBC)/sysdeps/gnu \
	-I$(EGLIBC)/sysdeps/unix/inet \
	-I$(EGLIBC)/ports/sysdeps/unix/sysv \
	-I$(EGLIBC)/nptl/sysdeps/unix/sysv \
	-I$(EGLIBC)/sysdeps/unix/sysv \
	-I$(EGLIBC)/ports/sysdeps/unix/arm \
	-I$(EGLIBC)/ports/sysdeps/unix \
	-I$(EGLIBC)/nptl/sysdeps/unix \
	-I$(EGLIBC)/sysdeps/unix \
	-I$(EGLIBC)/sysdeps/posix \
	-I$(EGLIBC)/ports/sysdeps/arm/armv7 \
	-I$(EGLIBC)/ports/sysdeps/arm/armv6t2 \
	-I$(EGLIBC)/ports/sysdeps/arm/nptl \
	-I$(EGLIBC)/ports/sysdeps/arm \
	-I$(EGLIBC)/sysdeps/wordsize-32 \
	-I$(EGLIBC)/sysdeps/ieee754/flt-32 \
	-I$(EGLIBC)/sysdeps/ieee754/dbl-64 \
	-I$(EGLIBC)/sysdeps/ieee754 \
	-I$(EGLIBC)/sysdeps/generic \
	-I$(EGLIBC)/ports \
	-I$(EGLIBC)/nptl \
	-I$(EGLIBC) \
	-I$(EGLIBC)/libio \
	-I. \
	-nostdinc \
	-isystem /usr/lib/gcc/arm-linux-gnueabihf/4.7/include \
	-isystem /usr/lib/gcc/arm-linux-gnueabihf/4.7/include-fixed \
	-isystem $(EGLIBC)/debian/include \
	-D_LIBC_REENTRANT \
	-include $(EGLIBC)/include/libc-symbols.h \
	-D_IO_MTSAFE_IO

LDFLAGS_START = -nostdlib \
	-nostartfiles \
	-static

LDFLAGS_END = $(EGLIBC)/build-tree/armhf-libc/csu/crt1.o \
	$(EGLIBC)/build-tree/armhf-libc/csu/crti.o \
	`$(CC) --print-file-name=crtbeginT.o`

LIBS = -Wl,--start-group \
	$(EGLIBC)/build-tree/armhf-libc/libc.a \
	-lgcc \
	-lgcc_eh \
	-Wl,--end-group \
	`$(CC) --print-file-name=crtend.o` \
	$(EGLIBC)/build-tree/armhf-libc/csu/crtn.o

OBJS = main.o string.o

all: libc-bench

clean:
	rm -f $(OBJS) libc-bench

test: all
	./libc-bench

libc-bench: $(OBJS)
	$(CC) $(LDFLAGS_START) -o $@ $(LDFLAGS_END) $(OBJS) $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) main.c -c -o main.o
malloc.o: malloc.c
	$(CC) $(CFLAGS) malloc.c -c -o malloc.o
pthread.o: pthread.c
	$(CC) $(CFLAGS) pthread.c -c -o pthread.o
regex.o: regex.c
	$(CC) $(CFLAGS) regex.c -c -o regex.o
stdio.o: stdio.c
	$(CC) $(CFLAGS) stdio.c -c -o stdio.o
string.o: string.c
	$(CC) $(CFLAGS) string.c -c -o string.o
utf8.o: utf8.c
	$(CC) $(CFLAGS) utf8.c -c -o utf8.o

