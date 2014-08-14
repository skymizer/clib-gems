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
#include "sscanf_test.h"

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
// sscanf
//===----------------------------------------------------------------------===//
PAT_F(sscanf, sscanf1)
{
  RUN(b_stdio_sscanf, 0);
}

//===----------------------------------------------------------------------===//
// vfscanf
//===----------------------------------------------------------------------===//
PAT_F(vfscanf, sprintf1)
{
  RUN(b_stdio_sprintf, 0);
}

//===----------------------------------------------------------------------===//
// putc
//===----------------------------------------------------------------------===//
PAT_F(putc, putcgetc)
{
  RUN(b_stdio_putcgetc, 0);
}

PAT_F(putc, pubcgetc_unlocked)
{
  RUN(b_stdio_putcgetc_unlocked, 0);
}

//===----------------------------------------------------------------------===//
// mbrtowc
//===----------------------------------------------------------------------===//
PAT_F(mbrtowc, one_by_one)
{
  RUN(b_utf8_onebyone, 0);
}

//===----------------------------------------------------------------------===//
// mbstowcs
//===----------------------------------------------------------------------===//
PAT_F(mbstowcs, bigbuf)
{
  RUN(b_utf8_bigbuf, 0);
}

//===----------------------------------------------------------------------===//
// getc
//===----------------------------------------------------------------------===//
PAT_F(getc, putcgetc)
{
  RUN(b_stdio_putcgetc, 0);
}

PAT_F(getc, pubcgetc_unlocked)
{
  RUN(b_stdio_putcgetc_unlocked, 0);
}

//===----------------------------------------------------------------------===//
// strstr
//===----------------------------------------------------------------------===//
PAT_F(strstr, strstr1)
{
  RUN(b_string_strstr, "abcdefghijklmnopqrstuvwxyz");
}

PAT_F(strstr, strstr2)
{
  RUN(b_string_strstr, "azbycxdwevfugthsirjqkplomn");
}

PAT_F(strstr, strstr3)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaacccccccccccc");
}

PAT_F(strstr, strstr4)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaac");
}

PAT_F(strstr, strstr5)
{
  RUN(b_string_strstr, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
}

//===----------------------------------------------------------------------===//
// regex
//===----------------------------------------------------------------------===//
PAT_F(regex, search1)
{
  RUN(b_regex_search, "(a|b|c)*d*b");
}

PAT_F(regex, search2)
{
  RUN(b_regex_search, "a{25}b");
}

PAT_F(regex, compile1)
{
  RUN(b_regex_compile, "(a|b|c)*d*b");
}

//===----------------------------------------------------------------------===//
// pthread_mutex_lock
//===----------------------------------------------------------------------===//
PAT_F(pthread_mutex_lock, createjoin1)
{
  RUN(b_pthread_createjoin_serial1, 0);
}

PAT_F(pthread_mutex_lock, createjoin2)
{
  RUN(b_pthread_createjoin_serial2, 0);
}

PAT_F(pthread_mutex_lock, create1)
{
  RUN(b_pthread_create_serial1, 0);
}

PAT_F(pthread_mutex_lock, uselesslock)
{
  RUN(b_pthread_uselesslock, 0);
}

//===----------------------------------------------------------------------===//
// malloc
//===----------------------------------------------------------------------===//
PAT_F(malloc, sparse_1)
{
  RUN(b_malloc_sparse, 0);
}

PAT_F(malloc, bubble_1)
{
  RUN(b_malloc_bubble, 0);
}

PAT_F(malloc, tiny1)
{
  RUN(b_malloc_tiny1, 0);
}

PAT_F(malloc, tiny2)
{
  RUN(b_malloc_tiny2, 0);
}

PAT_F(malloc, big1)
{
  RUN(b_malloc_big1, 0);
}

PAT_F(malloc, big2)
{
  RUN(b_malloc_big2, 0);
}

PAT_F(malloc, thread_stress_1)
{
  RUN(b_malloc_thread_stress, 0);
}

PAT_F(malloc, thread_local_1)
{
  RUN(b_malloc_thread_local, 0);
}

//===----------------------------------------------------------------------===//
// genops
//===----------------------------------------------------------------------===//
PAT_F(genops, putcgetc)
{
  RUN(b_stdio_putcgetc, 0);
}

PAT_F(genops, pubcgetc_unlocked)
{
  RUN(b_stdio_putcgetc_unlocked, 0);
}

PAT_F(genops, sscanf1)
{
  RUN(b_stdio_sscanf, 0);
}

//===----------------------------------------------------------------------===//
// pthread_create
//===----------------------------------------------------------------------===//
PAT_F(pthread_create, createjoin1)
{
  RUN(b_pthread_createjoin_serial1, 0);
}

PAT_F(pthread_create, createjoin2)
{
  RUN(b_pthread_createjoin_serial2, 0);
}

PAT_F(pthread_create, create1)
{
  RUN(b_pthread_create_serial1, 0);
}

//===----------------------------------------------------------------------===//
// rawmemchr
//===----------------------------------------------------------------------===//
PAT_F(rawmemchr, sscanf1)
{
  RUN(b_stdio_sscanf, 0);
}

//===----------------------------------------------------------------------===//
// strops(_IO_str_init_static_internal)
//===----------------------------------------------------------------------===//
PAT_F(strops, sscanf1)
{
  RUN(b_stdio_sscanf, 0);
}

//===----------------------------------------------------------------------===//
// isoc99_vsscanf
//===----------------------------------------------------------------------===//
PAT_F(isoc99_vsscanf, sscanf1)
{
  RUN(b_stdio_sscanf, 0);
}

//===----------------------------------------------------------------------===//
// dl-profstub
//===----------------------------------------------------------------------===//
PAT_F(dl_profstub, one_by_one)
{
  RUN(b_utf8_onebyone, 0);
}

//===----------------------------------------------------------------------===//
// gconv_simple
//===----------------------------------------------------------------------===//
PAT_F(gconv_simple, one_by_one)
{
  RUN(b_utf8_onebyone, 0);
}

//===----------------------------------------------------------------------===//
// memset
//===----------------------------------------------------------------------===//
PAT_F(memset, memset1)
{
  RUN(b_string_memset, 0);
}

//===----------------------------------------------------------------------===//
// strchr
//===----------------------------------------------------------------------===//
PAT_F(strchr, strchr1)
{
  RUN(b_string_strchr, 0);
}

//===----------------------------------------------------------------------===//
// strlen
//===----------------------------------------------------------------------===//
PAT_F(strlen, strlen1)
{
  RUN(b_string_strlen, 0);
}

/** \fn main
 *  \brief the main function
 */
int main(int argc, char* argv[])
{
  pat::Test::Initialize(&argc, argv);
  pat::Test::RunAll();
}
