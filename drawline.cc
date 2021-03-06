#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s in.ppm out.ppm xstart ystart xend yend red green blue alpha\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 11)
    usage(argv[0]);

  char *inFilename = argv[1];
  char *outFilename = argv[2];
  double xstart = atof(argv[3]);
  double ystart = atof(argv[4]);
  double xend   = atof(argv[5]);
  double yend   = atof(argv[6]);
  int red   = clamp(atoi(argv[7]));
  int green = clamp(atoi(argv[8]));
  int blue  = clamp(atoi(argv[9]));
  double alpha = clampa(atof(argv[10]));
  int width,height;

  unsigned char *buffer = read_ppm(inFilename,width,height);
  if(!buffer)
    {
      return -1;
    }
  
  //draw line
  if (drawline(buffer, width, height, xstart, ystart, xend, yend, red, green, blue, alpha))
    {
      if (write_ppm(outFilename, width, height, buffer))
	{
	  printf("Wrote %s\n", outFilename);
	}
      else
	{
	  printf("File write was unsuccessful\n");
	}
    }

  free(buffer);

  return 0;
}

