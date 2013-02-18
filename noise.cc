#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"

void usage(const char *progname)
{
  printf("Usage: %s in.ppm out.ppm noise\n", progname);
  printf("\noise: value between 0 and 1 that controls amount of noise\n");
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 4)
    usage(argv[0]);

  char *inFilename = argv[1];
  char *outFilename = argv[2];

  //convert noise to a double

  double noise = atof(argv[3]);

  int width,height;

  unsigned char *buffer = read_ppm(inFilename,width,height);

  for (int j=0; j<height; j++)
    {
      for (int k=0; k<width; k++)
	{
	  int index = 3*(k+j*width);     // compute offset into array for pixel (k,j)
	  double rnoise = 255. * noise * (((double)rand()/(double)RAND_MAX) - 0.5);
	  double gnoise = 255. * noise * (((double)rand()/(double)RAND_MAX) - 0.5);
	  double bnoise = 255. * noise * (((double)rand()/(double)RAND_MAX) - 0.5);
	  buffer[index + 0] = clamp(buffer[index + 0] + (int)(rnoise + 0.5));
	  buffer[index + 1] = clamp(buffer[index + 1] + (int)(gnoise + 0.5));
	  buffer[index + 2] = clamp(buffer[index + 2] + (int)(bnoise + 0.5));
	}
    }

  write_ppm(outFilename, width, height, buffer);

  free(buffer);

  return 0;
}
