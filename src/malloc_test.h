/*===- malloc_test.h ------------------------------------------------------===//
//
//                          The C Library Gems
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_MALLOC_H
#define LIBCBENCH_MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

size_t b_malloc_sparse(void *dummy);

size_t b_malloc_bubble(void *dummy);

size_t b_malloc_tiny1(void *dummy);

size_t b_malloc_tiny2(void *dummy);

size_t b_malloc_big1(void *dummy);

size_t b_malloc_big2(void *dummy);

size_t b_malloc_thread_stress(void *dummy);

size_t b_malloc_thread_local(void *dummy);

#ifdef __cplusplus
} // end of extern
#endif

#endif
