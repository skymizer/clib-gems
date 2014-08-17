/*===- sscanf.c -----------------------------------------------------------===//
//
//                          The C Library Gems
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

# define L(str) str

const char *str_double[] =
{
  L("-.10000E+020.20000E+020.25000E+010.40000E+010.50000E+010.12500E+01"),
  L("0.10000E+020.20000E+020.25000E+010.40000E+010.50000E+010.12500E+01"),
  L("-1234567E0198765432E0912345678901987654321091234567890198765432109"),
  L("-0.1000E+020.20000E+020.25000E+010.40000E+010.50000E+010.12500E+01")
};

const double val_double[] =
{
  -.10000E+02, 0.20000E+02, 0.25000E+01, 0.40000E+01, 0.50000E+01, 0.12500E+01,
  0.10000E+02, 0.20000E+02, 0.25000E+01, 0.40000E+01, 0.50000E+01, 0.12500E+01,
  -1234567E01, 98765432E09, 12345678901.0, 98765432109.0, 12345678901.0,
    98765432109.0,
  -0.1000E+02, 0.20000E+02, 0.25000E+01, 0.40000E+01, 0.50000E+01, 0.12500E+01
};

const char *str_long[] =
{
  L("-12345678987654321123456789987654321123456789987654321"),
  L("-12345678987654321123456789987654321123456789987654321"),
  L("-12,345,678987,654,321123,456,789987,654,321123,456,789987,654,321"),
  L("-12,345,678987,654,321123,456,789987,654,321123,456,789987,654,321")
};

const char *fmt_long[] =
{
  L("%9ld%9ld%9ld%9ld%9ld%9ld"),
  L("%I9ld%I9ld%I9ld%I9ld%I9ld%I9ld"),
  L("%'11ld%'11ld%'11ld%'11ld%'11ld%'11ld"),
  L("%I'11ld%I'11ld%I'11ld%I'11ld%I'11ld%I'11ld")
};

const long int val_long[] =
{
  -12345678, 987654321, 123456789, 987654321, 123456789, 987654321
};

struct test
{
  const char *str;
  const char *fmt;
  int retval;
} int_tests[] =
{
  { L("foo\n"), L("foo\nbar"), -1 },
  { L("foo\n"), L("foo bar"), -1 },
  { L("foo\n"), L("foo %d"), -1 },
  { L("foo\n"), L("foo\n%d"), -1 },
  { L("foon"), L("foonbar"), -1 },
  { L("foon"), L("foon%d"), -1 },
  { L("foo "), L("foo bar"), -1 },
  { L("foo "), L("foo %d"), -1 },
  { L("foo\t"), L("foo\tbar"), -1 },
  { L("foo\t"), L("foo bar"), -1 },
  { L("foo\t"), L("foo %d"), -1 },
  { L("foo\t"), L("foo\t%d"), -1 },
  { L("foo"), L("foo"), 0 },
  { L("foon"), L("foo bar"), 0 },
  { L("foon"), L("foo %d"), 0 },
  { L("foo "), L("fooxbar"), 0 },
  { L("foo "), L("foox%d"), 0 },
  { L("foo bar"), L("foon"), 0 },
  { L("foo bar"), L("foo bar"), 0 },
  { L("foo bar"), L("foo %d"), 0 },
  { L("foo bar"), L("foon%d"), 0 },
  { L("foo "), L("foo %n"), 0 },
  { L("foo%bar1"), L("foo%%bar%d"), 1 },
  /* Some OSes skip whitespace here while others don't.  */
  { L("foo \t %bar1"), L("foo%%bar%d"), 1 }
};

struct test double_tests[] =
{
  { L("-1"), L("%1g"), 0 },
  { L("-.1"), L("%2g"), 0 },
  { L("-inf"), L("%3g"), 0 },
  { L("+0"), L("%1g"),  },
  { L("-0x1p0"), L("%2g"), 1 },
  { L("-..1"), L("%g"), 0 },
  { L("-inf"), L("%g"), 1 }
};

size_t b_stdio_sscanf(void* dummy)
{
  double d[6];
  long l[6];
  int i, j;
  int result = 0;

  for (i = 0; i < 4; ++i)
    {
      if (sscanf (str_double[i], L("%11lf%11lf%11lf%11lf%11lf%11lf"),
		  &d[0], &d[1], &d[2], &d[3], &d[4], &d[5]) != 6)
	{
	  printf ("Double sscanf test %d wrong number of "
		  "assigned inputs\n", i);
	  result = 1;
	}
      else
	for (j = 0; j < 6; ++j)
	  if (d[j] != val_double[6 * i + j])
	    {
	      printf ("Double sscanf test %d failed (%g instead of %g)\n",
		      i, d[j], val_double[6 * i + j]);
	      result = 1;
	      break;
	    }
    }

  for (i = 0; i < sizeof (int_tests) / sizeof (int_tests[0]); ++i)
    {
      int dummy, ret;

      if ((ret = sscanf (int_tests[i].str, int_tests[i].fmt,
			 &dummy)) != int_tests[i].retval)
	{
	  printf ("int_tests[%d] returned %d != %d\n",
		  i, ret, int_tests[i].retval);
	  result = 1;
	}
    }

  for (i = 0; i < sizeof (double_tests) / sizeof (double_tests[0]); ++i)
    {
      double dummy;
      int ret;

      if ((ret = sscanf (double_tests[i].str, double_tests[i].fmt,
			 &dummy)) != double_tests[i].retval)
	{
	  printf ("double_tests[%d] returned %d != %d\n",
		  i, ret, double_tests[i].retval);
	  result = 1;
	}
    }

  return result;
}
