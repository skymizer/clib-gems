/*===- utf8_test.h --------------------------------------------------------===//
//
//                          The C Library Gems
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#ifndef LIBCBENCH_UTF8_H
#define LIBCBENCH_UTF8_H

#ifdef __cplusplus
extern "C" {
#endif

size_t b_utf8_bigbuf(void *dummy);

size_t b_utf8_onebyone(void *dummy);

#ifdef __cplusplus
} // end of extern
#endif

#endif
