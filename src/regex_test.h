/*===- regex_test.h -------------------------------------------------------===//
//
//                          The C Library Gems
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_REGEX_H
#define LIBCBENCH_REGEX_H

#ifdef __cplusplus
extern "C" {
#endif

size_t b_regex_compile(void *s);

size_t b_regex_search(void *s);

#ifdef __cplusplus
} // end of extern
#endif

#endif
