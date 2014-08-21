/*===- sprintf.c ----------------------------------------------------------===//
//
//                          The C Library Gems
//
//  This file is distributed under the GPLv2 License.
//  See LICENSE for details.
//
//===----------------------------------------------------------------------===*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

/* This page is covered by the following copyright:
 * (C) Copyright C E Chew
 *
 * Feel free to copy, use and distribute this software provided:
 *
 *	1. you do not pretend that you wrote it
 *	2. you leave this copyright notice intact.
 */

/*
 * Extracted from exercise.c for glibc-1.05 bug report by Bruce Evans.
 */

#define FORMAT "|%12.4f|%12.4e|%12.4g|\n"

size_t b_stdio_sprintf(void *dummy)
{
  static char shortstr[] = "Hi, Z.";
  static char longstr[] = "Good morning, Doctor Chandra.  This is Hal.  \
				I am ready for my first lesson today.";
  static char output[12000];

  sprintf(output,"decimal negative:\t\"%d\"\n", -2345);
  sprintf(output,"octal negative:\t\"%o\"\n", -2345);
  sprintf(output,"hex negative:\t\"%x\"\n", -2345);
  sprintf(output,"long decimal number:\t\"%ld\"\n", -123456L);
  sprintf(output,"long octal negative:\t\"%lo\"\n", -2345L);
  sprintf(output,"long unsigned decimal number:\t\"%lu\"\n", -123456L);
  sprintf(output,"zero-padded LDN:\t\"%010ld\"\n", -123456L);
  sprintf(output,"left-adjusted ZLDN:\t\"%-010ld\"\n", -123456L);
  sprintf(output,"space-padded LDN:\t\"%10ld\"\n", -123456L);
  sprintf(output,"left-adjusted SLDN:\t\"%-10ld\"\n", -123456L);

  sprintf(output,"zero-padded string:\t\"%010s\"\n", shortstr);
  sprintf(output,"left-adjusted Z string:\t\"%-010s\"\n", shortstr);
  sprintf(output,"space-padded string:\t\"%10s\"\n", shortstr);
  sprintf(output,"left-adjusted S string:\t\"%-10s\"\n", shortstr);
  sprintf(output,"limited string:\t\"%.22s\"\n", longstr);

  sprintf(output,"e-style >= 1:\t\"%e\"\n", 12.34);
  sprintf(output,"e-style >= .1:\t\"%e\"\n", 0.1234);
  sprintf(output,"e-style < .1:\t\"%e\"\n", 0.001234);
  sprintf(output,"e-style big:\t\"%.60e\"\n", 1e20);
  sprintf(output,"e-style == .1:\t\"%e\"\n", 0.1);
  sprintf(output,"f-style >= 1:\t\"%f\"\n", 12.34);
  sprintf(output,"f-style >= .1:\t\"%f\"\n", 0.1234);
  sprintf(output,"f-style < .1:\t\"%f\"\n", 0.001234);
  sprintf(output,"g-style >= 1:\t\"%g\"\n", 12.34);
  sprintf(output,"g-style >= .1:\t\"%g\"\n", 0.1234);
  sprintf(output,"g-style < .1:\t\"%g\"\n", 0.001234);
  sprintf(output,"g-style big:\t\"%.60g\"\n", 1e20);

  sprintf(output," %6.5f\n", .099999999860301614);
  sprintf(output," %6.5f\n", .1);
  sprintf(output,"x%5.4fx\n", .5);

  sprintf(output,"%#03x\n", 1);

  sprintf(output,"something really insane: %.10000f\n", 1.0);

  sprintf(output,"%15.5e\n", 4.9406564584124654e-324);

  sprintf(output,FORMAT, 0.0, 0.0, 0.0);
  sprintf(output,FORMAT, 1.0, 1.0, 1.0);
  sprintf(output,FORMAT, -1.0, -1.0, -1.0);
  sprintf(output,FORMAT, 100.0, 100.0, 100.0);
  sprintf(output,FORMAT, 1000.0, 1000.0, 1000.0);
  sprintf(output,FORMAT, 10000.0, 10000.0, 10000.0);
  sprintf(output,FORMAT, 12345.0, 12345.0, 12345.0);
  sprintf(output,FORMAT, 100000.0, 100000.0, 100000.0);
  sprintf(output,FORMAT, 123456.0, 123456.0, 123456.0);

  sprintf(output,"%e should be 1.234568e+06\n", 1234567.8);
  sprintf(output,"%f should be 1234567.800000\n", 1234567.8);
  sprintf(output,"%g should be 1.23457e+06\n", 1234567.8);
  sprintf(output,"%g should be 123.456\n", 123.456);
  sprintf(output,"%g should be 1e+06\n", 1000000.0);
  sprintf(output,"%g should be 10\n", 10.0);
  sprintf(output,"%g should be 0.02\n", 0.02);

  sprintf(output,"sprintf (\"%%hhu\", %u) = %hhu\n", UCHAR_MAX + 2, UCHAR_MAX + 2);
  sprintf(output,"sprintf (\"%%hu\", %u) = %hu\n", USHRT_MAX + 2, USHRT_MAX + 2);
  sprintf(output,"sprintf (\"%%hhi\", %i) = %hhi\n", UCHAR_MAX + 2, UCHAR_MAX + 2);
  sprintf(output,"sprintf (\"%%hi\", %i) = %hi\n", USHRT_MAX + 2, USHRT_MAX + 2);

  sprintf(output,"sprintf (\"%%1$hhu\", %2$u) = %1$hhu\n",
	  					   UCHAR_MAX + 2, UCHAR_MAX + 2);
  sprintf(output,"sprintf (\"%%1$hu\", %2$u) = %1$hu\n", USHRT_MAX + 2, USHRT_MAX + 2);
  sprintf(output,"sprintf (\"%%1$hhi\", %2$i) = %1$hhi\n",
	  					   UCHAR_MAX + 2, UCHAR_MAX + 2);
  sprintf(output,"sprintf (\"%%1$hi\", %2$i) = %1$hi\n", USHRT_MAX + 2, USHRT_MAX + 2);

  return 0;
}
