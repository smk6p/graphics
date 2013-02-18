#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void usage(const char *progname)
{
  printf("Usage: %s\n", progname);
  exit(0);
}

void test(bool testcase, char *s1, char *s2)
{
 printf("%s %s\n", s1, s2); 
 if (mystrcmp(s1, s2) == testcase)
    {
      printf("Test passed.\n");
    }
  else
    {
      printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
  if (argc != 1)
    usage(argv[0]);

  test(true, "cat", "CaT");
  test(false, "0aB", "1Ab");
  test(true, "ABc", "abc");
  test(false, "ABc", "adc");
  test(true, "ABc", "abc");
  test(false, "Abcd", "abc");
  test(true, "aBc", "abC");
  test(false, "a?c", "a_c");
  test(true, "xyZ", "XYz");
  test(false, "ABZ", "ABY");
  
  return 0;
}
