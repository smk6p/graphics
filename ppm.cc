#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *
read_ppm(char *inFilename, int &width, int &height)
{
  FILE *in = fopen(inFilename,"r");
  if (!in)
    {
      fprintf(stderr, "Failed to open file: %s\n", inFilename);
      return 0;
    }

  char line[1024];
  if (!fgets(line,1024,in))
    {
      fprintf(stderr, "Unexpected EOF in file: %s\n", inFilename);
      return 0;
    }

  if ( ( (line[0] != 'P') && (line[0] != 'p') ) || line[1] != '6')
    {
      fprintf(stderr, "Invalid header: %s\n", inFilename);
      return 0;
    }

  fgets(line,1024,in);

  while (line[0] == '#')
    fgets(line,1024,in);

  sscanf(line, "%d %d", &width, &height);

  //test to see if width, height set
  if(width <= 0 || height <= 0)
    {
      fprintf(stderr, "Invalid width or height: %s\n", inFilename);
      return 0;
    }
 
  fgets(line,1024,in);
  while (line[0] == '#')
    fgets(line,1024,in);

  unsigned char *buffer = (unsigned char *)malloc(width*height*3);

  if(fread(buffer, 1, width*height*3, in) < (unsigned int)(width*height*3))
    {
      fprintf(stderr, "Unexpected EOF: %s\n", inFilename);
      return 0;
    }

  fclose(in);

  return buffer;
}

bool
write_ppm(char *outFilename, int width, int height, unsigned char *buffer)
{
  //writes a ppm file with given height and width values to file outFilename

  FILE* imageFile = fopen(outFilename,"w");

  if (imageFile == NULL)
    {
      fprintf(stderr,"Unable to create file.\n");
      return false;
    }
  
  fprintf(imageFile,"%s\n","P6");
  fprintf(imageFile,"%d %d\n",width,height);
  fprintf(imageFile,"%d\n",255);
  fwrite(buffer,1,3*width*height,imageFile);

  fclose(imageFile);
  return true;
}
