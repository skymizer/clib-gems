#ifndef LIBCBENCH_PTHREAD_H
#define LIBCBENCH_PTHREAD_H

void *emptyfunc(void *dummy);

size_t b_pthread_createjoin_serial1(void *dummy);

size_t b_pthread_createjoin_serial2(void *dummy);

size_t b_pthread_create_serial1(void *dummy);

void *lockunlock(void *mut);

size_t b_pthread_uselesslock(void *dummy);
#endif
