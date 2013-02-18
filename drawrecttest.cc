#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s\n", progname);
  exit(0);
}

void test(bool testcase, unsigned char *buffer, int width, int height, int top, int bottom, int left, int right, int red, int green, int blue, double alpha)
{
  printf("%d %d %d %d %d %d %d %d %d %f\n", width, height, top, bottom, left, right, red, green, blue, alpha); 
  if (drawrect(buffer, width, height, top, bottom, left, right, red, green, blue, alpha) == testcase)
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

  char *inFilename = (char*)("balloons.ppm");
  char *outFilename = (char*)("balloons3.ppm");
  int width, height;
  
  unsigned char *buffer = read_ppm(inFilename,width,height);
  if(!buffer)
    {
      return -1;
    }

  test(true, buffer, width, height, 200, 400, 300, 500, 255, 0, 0, 0.5);
  test(false, buffer, width, height, 400, 200, 100, 300, 0, 0, 0, 1);
  test(true, buffer, width, height, -200, 400, 300, 500, 255, 255, 0, 0.4);
  test(false, buffer, width, height, -400, -200, -300, -100, 255, 0, 0, .5);
  test(true, buffer, width, height, 200, 4000, 300, 500, 255, 0, 255, 0.6);
  test(true, buffer, width, height, 200, 400, 300, 700, 0, 255, 0, .1);
  test(true, buffer, width, height, 200, 400, -300, 500, 0, 255, 255, 0.3);
  test(false, buffer, width, height, 200, 400, 300, 100, 0, 0, 255, 1);
  test(true, buffer, width, height, 200, 400, 300, 5000, 0, 0, 0, 2);
  test(false, buffer, width, height, 4000, 5000, 3000, 4000, 255, 255, 255, .5);
  
  if (write_ppm(outFilename, width, height, buffer))
    {
      printf("Wrote %s\n", outFilename);
    }
  else
    {
      printf("File write was unsuccessful\n");
      return -1;
    }
   
  free(buffer);

  return 0;
}
