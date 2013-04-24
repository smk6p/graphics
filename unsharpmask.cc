#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s image.ppm sigma alpha out.ppm out2.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 6)
    usage(argv[0]);

  char *image = argv[1];
  int sigma = atoi(argv[2]);
  float alpha = atof(argv[3]);
  char *out = argv[4];
  char *out2 = argv[5];

  int w,h,fw,fh;

  fw = 4*sigma + 1;
  fh = 4*sigma + 1;
  
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
	  float x = (float)(i - 2*sigma);
	  float y = (float)(j - 2*sigma);
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
  unsigned char *outBuffer2 = (unsigned char*)malloc(sizeof(unsigned char)*w*h*3);
  for (int l = 0; l < h; l++)
    {
      for (int k = 0; k < w; k++)
	{
	  int index = 3*(k + l*w);
	  outBuffer2[index + 0] = (unsigned char)(clampval((int)((float)(1.f + alpha)*buffer[index + 0] - (float)alpha*outBuffer[index + 0] + 0.5), 0, 255)); 
	  outBuffer2[index + 1] = (unsigned char)(clampval((int)((float)(1.f + alpha)*buffer[index + 1] - (float)alpha*outBuffer[index + 1] + 0.5), 0, 255)); 
	  outBuffer2[index + 2] = (unsigned char)(clampval((int)((float)(1.f + alpha)*buffer[index + 2] - (float)alpha*outBuffer[index + 2] + 0.5), 0, 255)); 
	}
    }
  if (write_ppm(out2, w, h, outBuffer2))
    {
      printf("Wrote %s\n", out2);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }
  return 0;
}
