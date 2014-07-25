/*===- string_test.h ------------------------------------------------------===//
//
//                          The LibC-Bench Project
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_STRING_H
#define LIBCBENCH_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

size_t b_string_strstr(void *dummy);

size_t b_string_memset(void *dummy);

size_t b_string_strchr(void *dummy);

size_t b_string_strlen(void *dummy);

#ifdef __cplusplus
} // end of extern
#endif

#endif
