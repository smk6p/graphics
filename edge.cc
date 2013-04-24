#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s image.ppm out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 3)
    usage(argv[0]);

  char *image = argv[1];
  char *out = argv[2];

  int w,h;
  int fw = 3;
  int fh = 1;

  unsigned char *buffer = read_ppm(image,w,h);
  if(!buffer)
    {
      return -1;
    }
 
  float *filterBuffer = (float*)malloc(sizeof(float)*fw*fh);
  
  if(!filterBuffer)
    {
      return -1;
    }
  for (int j = 0; j < fh; j++)
    {
      for (int i = 0; i < fw; i++)
	{
	  int index = i + j*fw;
	  filterBuffer[index] = 0.5*(float)i - 0.5;
	}
    }

  unsigned char *outBuffer = convolve(buffer, filterBuffer, w, h, fw, fh);
  unsigned char *outBuffer2 = (unsigned char*)malloc(sizeof(unsigned char)*3*w*h);
  for (int j = 0; j < h; j++)
    {
      for (int i = 0; i < w; i++)
	{
	  int index = 3*(i + j*w);
	  outBuffer2[index + 0] = 2*abs(outBuffer[index + 0]);
	  outBuffer2[index + 1] = 2*abs(outBuffer[index + 1]);
	  outBuffer2[index + 2] = 2*abs(outBuffer[index + 2]);
	}
    }
  
  if (write_ppm(out, w, h, outBuffer))
    {
      printf("Wrote %s\n", out);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }


  free(buffer);
  free(filterBuffer);
  free(outBuffer);
  free(outBuffer2);
  return 0;
}

