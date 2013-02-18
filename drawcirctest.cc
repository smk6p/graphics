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

void test(bool testcase, unsigned char *buffer, int width, int height, double cx, double cy, double radius, int red, int green, int blue, double alpha)
{
  printf("%d %d %f %f %f %d %d %d %f\n", width, height, cx, cy, radius, red, green, blue, alpha); 
  if (drawcirc(buffer, width, height, cx, cy, radius, red, green, blue, alpha) == testcase)
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

  test(true, buffer, width, height, 400, 400, 200, 255, 0, 0, 0.5);
  test(false, buffer, width, height, 400, 200, -100, 0, 0, 0, 1);
  test(true, buffer, width, height, -200, 400, 300, 255, 255, 0, 0.4);
  test(false, buffer, width, height, -400, -200, 100, 255, 0, 0, .5);
  test(true, buffer, width, height, 200, 4000, 3500, 255, 0, 255, 0.6);
  test(false, buffer, width, height, 3000, 400, 100, 0, 255, 0, .1);
  test(true, buffer, width, height, 200, 400, 500, 0, 255, 255, -0.3);
  test(false, buffer, width, height, 200, 4000, 100, 0, 0, 255, 1);
  test(true, buffer, width, height, 200, 400, 5000, 0, 255, 0, 2);
  test(false, buffer, width, height, 4000, 5000, 100, 255, 255, 255, .5);
  
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
