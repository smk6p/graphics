#include <stdio.h>
#include <stdlib.h>

void usage(const char *progname)
{
  printf("Usage: %s width height image.ppm\n", progname);
  exit(0);
}

int main(int argc, char* argv[])
{
  // print out argument data
  printf("%d\n",argc);
  for(int i=0;i<argc;i++)
    {
      printf("%s\n",argv[i]);
    }
  // check if there are enough args

  if (argc != 4)
    {
      usage(argv[0]);
    }
  // create image
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  char* image = argv[3];

  // allocate memory for an 8-bit RGB image of dimensions width x height
  unsigned char *buffer = (unsigned char *)malloc(sizeof(unsigned char)*width*height*3);

  for (int j=0; j<height; j++)
    {
      for (int k=0; k<width; k++)
	{
	  int index = 3*(k+j*width);     // compute offset into array for pixel (k,j)
	  buffer[index + 0] = 255 - 255*k/width;
	  buffer[index + 1] = 255*k/width;
	  buffer[index + 2] = 255*j/height;
	}
    }

  FILE* imageFile = fopen(image,"w");

  if (imageFile == NULL)
    {
      fprintf(stderr,"Unable to create file.\n");
      return -1;
    }

  fprintf(imageFile,"%s\n","P6");
  fprintf(imageFile,"%d %d\n",width,height);
  fprintf(imageFile,"%d\n",255);
  fwrite(buffer,1,3*width*height,imageFile);

  fclose(imageFile);

  // clean up memory
  free(buffer);

  return 0;
}
