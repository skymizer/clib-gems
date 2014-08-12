//===- main.cpp -----------------------------------------------------------===//
//
//                          The LibC-Bench Project
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <pat/pat.h>
#include "regex_test.h"
#include "malloc_test.h"
#include "pthread_test.h"
#include "stdio_test.h"
#include "string_test.h"
#include "utf8_test.h"
#include "sprintf_test.h"

//===----------------------------------------------------------------------===//
// Helpers
//===----------------------------------------------------------------------===//
/** \fn run_bench
 *  \brief run_bench is a function wrapper to avoid inter-procedure optimization
 *
 *  If we run the function directly, then compiler has highly chance to inline
 *  or unroll the function body. Our purpose is to run the original function
 *  body and all improvement should be counted in C library, not benchmark
 *  itself.
 */
int run_bench(size_t (*bench)(void *), void *params)
{
  bench(params);
  return 0;
}

#define RUN(_func_, _params_) \
  PERFORM { run_bench((_func_), (void*)(_params_)); }

//===----------------------------------------------------------------------===//
// Malloc Test Functions
//===----------------------------------------------------------------------===//
PAT_F(malloc_case, sparse_1)
{
  RUN(b_malloc_sparse, 0);
}

PAT_F(malloc_case, bubble_1)
{
  RUN(b_malloc_bubble, 0);
}

PAT_F(malloc_case, tiny1)
{
  RUN(b_malloc_tiny1, 0);
}

PAT_F(malloc_case, tiny2)
{
  RUN(b_malloc_tiny2, 0);
}

PAT_F(malloc_case, big1)
{
  RUN(b_malloc_big1, 0);
}

PAT_F(malloc_case, big2)
{
  RUN(b_malloc_big2, 0);
}

PAT_F(malloc_case, thread_stress_1)
{
  RUN(b_malloc_thread_stress, 0);
}

PAT_F(malloc_case, thread_local_1)
{
  RUN(b_malloc_thread_local, 0);
}

//===----------------------------------------------------------------------===//
// Pthread Test Functions
//===----------------------------------------------------------------------===//
PAT_F(pthread_case, createjoin1)
{
  RUN(b_pthread_createjoin_serial1, 0);
}

PAT_F(pthread_case, createjoin2)
{
  RUN(b_pthread_createjoin_serial2, 0);
}

PAT_F(pthread_case, create1)
{
  RUN(b_pthread_create_serial1, 0);
}

PAT_F(pthread_case, uselesslock)
{
  RUN(b_pthread_uselesslock, 0);
}

//===----------------------------------------------------------------------===//
// Regular Expression
//===----------------------------------------------------------------------===//
PAT_F(regex_case, compile1)
{
  RUN(b_regex_compile, "(a|b|c)*d*b");
}

PAT_F(regex_case, search1)
{
  RUN(b_regex_search, "(a|b|c)*d*b");
}

PAT_F(regex_case, search2)
{
  RUN(b_regex_search, "a{25}b");
}

//===----------------------------------------------------------------------===//
// Std I/O Test
//===----------------------------------------------------------------------===//
PAT_F(stdio_case, putcgetc)
{
  RUN(b_stdio_putcgetc, 0);
}

PAT_F(stdio_case, pubcgetc_unlocked)
{
  RUN(b_stdio_putcgetc_unlocked, 0);
}

PAT_F(stdio_case, sprintf1)
{
  RUN(b_string_sprintf, 0);
}

//===----------------------------------------------------------------------===//
// String Test
//===----------------------------------------------------------------------===//
PAT_F(string_case, strstr1)
{
  RUN(b_string_strstr, "abcdefghijklmnopqrstuvwxyz");
}

PAT_F(string_case, strstr2)
{
  RUN(b_string_strstr, "azbycxdwevfugthsirjqkplomn");
}

PAT_F(string_case, strstr3)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaacccccccccccc");
}

PAT_F(string_case, strstr4)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaac");
}

PAT_F(string_case, strstr5)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
}

PAT_F(string_case, memset1)
{
  RUN(b_string_memset, 0);
}

PAT_F(string_case, strchr1)
{
  RUN(b_string_strchr, 0);
}

PAT_F(string_case, strlen1)
{
  RUN(b_string_strlen, 0);
}

//===----------------------------------------------------------------------===//
// UTF-8 Test
//===----------------------------------------------------------------------===//
PAT_F(utf8_case, bigbuf)
{
  RUN(b_utf8_bigbuf, 0);
}

PAT_F(utf8_case, one_by_one)
{
  RUN(b_utf8_onebyone, 0);
}

/** \fn main
 *  \brief the main function
 */
int main(int argc, char* argv[])
{
  pat::Test::Initialize(&argc, argv);
  pat::Test::RunAll();
}
