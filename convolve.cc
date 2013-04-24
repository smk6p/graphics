#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"
#include "draw2D.h"

void usage(const char *progname)
{
  printf("Usage: %s image.ppm filter.ppm out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 4)
    usage(argv[0]);

  char *image = argv[1];
  char *filter = argv[2];
  char *out = argv[3];
  
  int w,h,fw,fh;

  unsigned char *buffer = read_ppm(image,w,h);
  if(!buffer)
    {
      return -1;
    }
  unsigned char *fBuffer = read_ppm((char*)filter,fw,fh);
  if(!fBuffer)
    {
      return -1;
    }
  if (!isOdd(fw) || !isOdd(fh))
    {
      printf("Filter width and height must be odd\n");
      return -1;
    }

  float *filterBuffer = (float*)malloc(sizeof(float)*fw*fh);
  
  if(!filterBuffer)
    {
      return -1;
    }
  for (int i = 0; i < fw*fh; i++)
    {
      int index = 3*i;
      //assign monochromatic filter values in range 0 - 1
      filterBuffer[i] = ((float)(fBuffer[index + 0])*0.3 +
			 (float)(fBuffer[index + 1])*0.59 + 
			 (float)(fBuffer[index + 2])*0.11)/255.f;
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
  
  free(buffer);
  free(filterBuffer);
  free(outBuffer);
  free(fBuffer);

  return 0;
}

