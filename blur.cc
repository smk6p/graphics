#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s image.ppm radius out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 4)
    usage(argv[0]);

  char *image = argv[1];
  int radius = atoi(argv[2]);
  char *out = argv[3];

  int w,h,fw,fh;

  fw = 2*radius + 1;
  fh = 2*radius + 1;
  float sigma = (float)radius/2.f;

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
	  float x = (float)(i - radius);
	  float y = (float)(j - radius);
	  filterBuffer[index] = exp(-1.f*(x*x + y*y)/(2.f*sigma*sigma));
	}
    }
  unsigned char *outBuffer = convolve(buffer, filterBuffer, w, h, fw, fh);
  if (write_ppm(out, w, h, outBuffer))
    {
      printf("Wrote %s\n", out);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }

  /*unsigned char *out2Buffer = (unsigned char *)malloc(w*h*3);
  for (int j=0; j<h; j++)
    {
      for (int i=0; i<w; i++)
	{
	  for (int c=0; c<3; c++)
	    out2Buffer[j*w*3+i*3+c] = (int)(0.5f + fabs((float)buffer[j*w*3+i*3+c] - (float)outBuffer[j*w*3+i*3+c]));
	}
    }
    write_ppm((char *)"high.ppm", w, h, out2Buffer);*/
  
  free(buffer);
  free(filterBuffer);
  free(outBuffer);

  return 0;
}
