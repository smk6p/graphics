#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"

void usage(const char *progname)
{
  printf("Usage: %s in.ppm out.ppm xstart ystart xend yend red green blue\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 10)
    usage(argv[0]);

  char *inFilename = argv[1];
  char *outFilename = argv[2];
  int xstart = atoi(argv[3]);
  int ystart = atoi(argv[4]);
  int xend   = atoi(argv[5]);
  int yend   = atoi(argv[6]);
  int red   = clamp(atoi(argv[7]));
  int green = clamp(atoi(argv[8]));
  int blue  = clamp(atoi(argv[9]));

  int width,height;

  unsigned char *buffer = read_ppm(inFilename,width,height);
  if(!buffer)
    {
      return -1;
    }
  
  //draw line 
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

