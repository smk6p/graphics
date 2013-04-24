#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "util.h"
//Prints proper usage of the program
void usage(const char *progname)
{
  printf("Usage: %s #width #height #red #blue #green out.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  if (argc != 7)
    usage(argv[0]);

  // create image
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  int red   = clamp(atoi(argv[3])); 
  int green = clamp(atoi(argv[4]));
  int blue  = clamp(atoi(argv[5]));
  
  char *outFilename = argv[6];

  // allocate memory for an 8-bit RGB image of dimensions width x height
  unsigned char *buffer = (unsigned char *)malloc(sizeof(unsigned char)*width*height*3);

  for (int j=0; j<height; j++)
    {
      for (int k=0; k<width; k++)
	{
	  int index = 3*(k+j*width);     // compute offset into array for pixel (k,j)
	  buffer[index + 0] = red;
	  buffer[index + 1] = green;
	  buffer[index + 2] = blue;
	}
    }

  /*int midwidth = width/2;
  int midheight = height/2;
  buffer[3*(midwidth + midheight*width) + 0] = 255;
  buffer[3*(midwidth + midheight*width) + 1] = 255;
  buffer[3*(midwidth + midheight*width) + 2] = 255;*/
  
  if(write_ppm(outFilename,width,height,buffer))
    {
      printf("Wrote %s\n", outFilename);
    }
  else
    {
      printf("File write was unsuccessful\n");
    }
  

  // clean up memory
  free(buffer);

  return 0;
}
