#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <linux/perf_event.h>
#include <sys/ioctl.h>

#ifndef __NR_perf_event_open
#define __NR_perf_event_open 364
#endif

static inline int
sys_perf_event_open(struct perf_event_attr *attr, pid_t pid,
                    int cpu, int group_fd, unsigned long flags)
{
  attr->size = sizeof(*attr);
  return syscall(__NR_perf_event_open, attr, pid, cpu, group_fd, flags);
}

inline static int
setup_perf_event()
{
  struct perf_event_attr attr;
  int fd;

  memset(&attr, 0, sizeof(attr));

  attr.inherit = 1;
  attr.disabled = 1;
//  attr.type = PERF_TYPE_HARDWARE;
//  attr.config = PERF_COUNT_HW_CPU_CYCLES;
  attr.type = PERF_TYPE_SOFTWARE;
  attr.config = PERF_COUNT_SW_TASK_CLOCK;

  fd = sys_perf_event_open(&attr, 0, -1, -1, 0);

  return fd;
}

inline static void start_perf_event(int fd)
{
  ioctl(fd, PERF_EVENT_IOC_ENABLE);
}

inline static void stop_perf_event(int fd)
{
  ioctl(fd, PERF_EVENT_IOC_DISABLE);
}

inline static unsigned long long read_perf_event(int fd)
{
  unsigned long long cycle;

  read(fd, &cycle, sizeof(unsigned long long));

  return cycle;
}

int run_bench(const char *label, size_t (*bench)(void *), void *params)
{
  int fd;
  unsigned long long cycles;

  fd = setup_perf_event();
  start_perf_event(fd);
  cycles = read_perf_event(fd);

  bench(params);

  cycles = read_perf_event(fd) - cycles;
  printf("%llu,", cycles);
  stop_perf_event(fd);

  return 0;
}

#define RUN(a, b) \
  extern size_t (a)(void *); \
  run_bench(#a " (" #b ")", (a), (b))

int main()
{
  RUN(b_string_strstr, "abcdefghijklmnopqrstuvwxyz");
  RUN(b_string_strstr, "azbycxdwevfugthsirjqkplomn");
  RUN(b_string_strstr, "aaaaaaaaaaaaaacccccccccccc");
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaac");
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
  RUN(b_string_memset, 0);
  RUN(b_string_strchr, 0);
  RUN(b_string_strlen, 0);
}
