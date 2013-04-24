#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"

void usage(const char *progname)
{
  printf("Usage: %s image.ppm factor out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 4)
    usage(argv[0]);

  char *image = argv[1];
  int factor = atoi(argv[2]);
  char *out = argv[3];

  int w,h,outw,outh;

  unsigned char *buffer = read_ppm(image,w,h);
  if(!buffer)
    {
      return -1;
    }

  outw = (int)((double)w/(double)factor + 0.5);
  outh = (int)((double)h/(double)factor + 0.5);
  
  unsigned char *outBuffer = (unsigned char*)malloc(sizeof(unsigned char)*3*outw*outh);
  
  for (int j = 0; j < outh; j++)
    {
      for (int i = 0; i < outw; i++)
	{
	  float xp = (float)i + 0.5f;
	  float yp = (float)j + 0.5f;
	  
	  float x = xp*(float)factor;
	  float y = yp*(float)factor;
	  
	  int _i = (int)(x);
	  int _j = (int)(y);
	  _i = clampval(_i, 0, w - 1);
	  _j = clampval(_j, 0, h - 1);

	  int index = 3*(i + j*outw);
	  int index2 = 3*(_i + _j*w);
	  
	  outBuffer[index + 0] = buffer[index2 + 0];
	  outBuffer[index + 1] = buffer[index2 + 1];
	  outBuffer[index + 2] = buffer[index2 + 2];
	}
    }
  
    if (write_ppm(out,outw, outh, outBuffer))
    {
      printf("Wrote %s\n", out);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }
  
  free(buffer);
  free(outBuffer);
  return 0;
}
