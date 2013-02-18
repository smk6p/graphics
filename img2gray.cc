#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

void usage(const char *progname)
{
  printf("Usage: %s in.ppm out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 3)
    usage(argv[0]);

  char *inFilename = argv[1];
  char *outFilename = argv[2];

  int width,height;

  unsigned char *buffer = read_ppm(inFilename,width,height);
  if(!buffer)
    {
      return -1;
    }
  
  // TODO: convert image into grayscale

  for (int j=0; j<height; j++)
    {
      for (int k=0; k<width; k++)
	{
	  int index = 3*(k+j*width);     // compute offset into array for pixel (k,j)
	  int luminance = (int)(0.30f*(float)buffer[index]) + 
	                  (int)(0.59f*(float)buffer[index + 1]) + 
	                  (int)(0.11f*(float)buffer[index + 2]); //compute luminance 
	  // convert to grayscale
	  buffer[index + 0] = luminance;
	  buffer[index + 1] = luminance;
	  buffer[index + 2] = luminance;
	}
    }

  if (write_ppm(outFilename, width, height, buffer))
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
