#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"

void usage(const char *progname)
{
  printf("Usage: %s in.ppm out.ppm xstart ystart xend yend\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 7)
    usage(argv[0]);

  char *inFilename = argv[1];
  char *outFilename = argv[2];
  int xstart = atoi(argv[3]);
  int ystart = atoi(argv[4]);
  int xend   = atoi(argv[5]);
  int yend   = atoi(argv[6]);

  int width, height;

  unsigned char *buffer = read_ppm(inFilename,width,height);
  if(!buffer)
    {
      return -1;
    }

  if (xstart > xend || ystart > yend || xstart > width || ystart > height || xend < 0 || yend < 0)
    {
      printf ("Crop out of bounds.\n");
      return -1;
    }

  if (xstart < 0)
    {
      xstart = 0;
    }

  if (ystart < 0)
    {
      ystart = 0;
    }

  if (xend > width)
    {
      xend = width;
    }

  if (yend > height)
    {
      yend = height;
    }

  for (int i = 0; i < (yend - ystart); i++)
    {
      for (int j = 0; j < (xend - xstart); j++)
	{
	  int index = 3*(xstart + j + (ystart + i)*width);
	  int index2 = 3*(j + i*(xend - xstart));
	  buffer[index2 + 0] = buffer[index + 0];
	  buffer[index2 + 1] = buffer[index + 1];
	  buffer[index2 + 2] = buffer[index + 2];
	}
    }

  //draw line
  if (write_ppm(outFilename, xend - xstart, yend - ystart, buffer))
    {
      printf("Wrote %s\n", outFilename);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }

  free(buffer);

  return 0;
}

