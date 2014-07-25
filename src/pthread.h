/*===- pthread.h ----------------------------------------------------------===//
//
//                          The LibC-Bench Project
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_PTHREAD_H
#define LIBCBENCH_PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

void *emptyfunc(void *dummy);

size_t b_pthread_createjoin_serial1(void *dummy);

size_t b_pthread_createjoin_serial2(void *dummy);

size_t b_pthread_create_serial1(void *dummy);

void *lockunlock(void *mut);

size_t b_pthread_uselesslock(void *dummy);

#ifdef __cplusplus
} // end of extern
#endif

#endif
