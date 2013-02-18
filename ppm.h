#ifndef __PPM_H__
#define __PPM_H__

unsigned char *
read_ppm(char *inFilename, int &width, int &height);

bool
write_ppm(char *outFilename, int width, int height, unsigned char *buffer);


#endif
