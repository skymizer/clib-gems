/*===- stdio_test.h -------------------------------------------------------===//
//
//                          The LibC-Bench Project
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_STDIO_H
#define LIBCBENCH_STDIO_H

#ifdef __cplusplus
extern "C" {
#endif

size_t b_stdio_putcgetc(void *dummy);

size_t b_stdio_putcgetc_unlocked(void *dummy);

#ifdef __cplusplus
} // end of extern
#endif

#endif
