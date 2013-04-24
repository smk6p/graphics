#include <stdio.h>
#include <stdlib.h>
#include "util.h"

bool drawrect(unsigned char *buffer,
	      int width,
	      int height,
	      int top,
	      int bottom,
	      int left,
	      int right,
	      int red,
	      int green,
	      int blue,
	      double alpha)
{
  red = clamp(red);
  green = clamp(green);
  blue = clamp(blue);
  alpha = clampa(alpha);

  //draw rectangle
   if (top > height || left > width || bottom < 0 || right < 0)
    {
      printf("Warning. Rectangle out of bounds\n");
      return false;
    }
   if (top < 0)
     {
       top = 0;
     }
   if (left < 0)
     { 
       left = 0;
     }
   if (bottom > height)
     {
       bottom = height;
     }
   if (right > width)
     {
       right = width;
     }
   if (top > bottom || left > right)
     {
       printf("Warning. Invalid coordinates\n");
       return false;
     }
   for (int i = 0; i < (bottom - top); i++)
     {
       for (int j = 0; j < (right - left); j++)
	 {
	   int index = 3*(left + j + (top + i)*width);
	   buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
	   buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
	   buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
	 }
     }

  return true;
}

bool isInsideCircle(double cx, double cy, double radius, double x, double y)
{
  double dx = cx - x;
  double dy = cy - y;
  if ((dx*dx + dy*dy) < (radius*radius))
    {
      return true;
    }
  return false;
}

bool drawcirc(unsigned char *buffer,
	      int width,
	      int height,
	      double cx,
	      double cy,
	      double radius,
	      int red,
	      int green,
	      int blue,
	      double alpha)
{
  red = clamp(red);
  green = clamp(green);
  blue = clamp(blue);
  alpha = clampa(alpha);
  
  if (radius < 0)
    {
      printf("Invalid radius.\n");
      return false;
    }

  double top = cy - radius;
  double bottom = cy + radius;
  double left = cx - radius;
  double right = cx + radius;

   if (top > height || left > width || bottom < 0 || right < 0)
    {
      printf("Warning. Circle out of bounds\n");
      return false;
    }
   if (top < 0)
     {
       top = 0;
     }
   if (left < 0)
     { 
       left = 0;
     }
   if (bottom > height)
     {
       bottom = height;
     }
   if (right > width)
     {
       right = width;
     }

   for (int i = 0; i < (bottom - top); i++)
     {
       for (int j = 0; j < (right - left); j++)
	 {
	   int index = 3*(left + j + (top + i)*width);
	   if (isInsideCircle(cx, cy, radius, j + .5 + left, i + .5 + top))
	     {
	       buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
	       buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
	       buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
	     }
	 }
     }
   return true;
}

bool drawline(unsigned char *buffer,
	      int width,
	      int height,
	      double xstart,
	      double ystart,
	      double xend,
	      double yend,
	      int red,
	      int green,
	      int blue,
	      double alpha)
{
  red = clamp(red);
  green = clamp(green);
  blue = clamp(blue);
  alpha = clampa(alpha);
  if (xend == xstart)
    {
      if (ystart > yend)
	{
	  for (int i = 0; i < (int)(ystart - yend); i++)
	    {
	      int x = (int)(xend + 0.5);
	      int y = (int)(yend + i + 0.5);
	      int index = 3*(x + y*width);
	      if (x >= 0 && x <= width && y >= 0 && y <= height)
		{                                                                    
		  buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		  buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		  buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		}
	    }
	}
      else
	{
	   for (int i = 0; i < (int)(yend - ystart); i++)
	    {
	      int x = (int)(xstart + 0.5);
	      int y = (int)(ystart + i + 0.5);
	      int index = 3*(x + y*width);
	      if (x >= 0 && x <= width && y >= 0 && y <= height)
		{                                                                    
		  buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		  buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		  buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		}
	    }
	}
    }
  else
    {
      double m = (yend - ystart)/(xend - xstart);
  
      if (m >= -1.0 && m <= 1.0)
	{
	  if (xstart > xend)
	    {
	      for (int i = 0; i < (int)(xstart - xend); i++)
		{
		  int x = (int)(xend + i + 0.5);
		  int y = (int)(yend + m*i + 0.5);
		  int index = 3*(x + y*width);
		  if (x >= 0 && x <= width && y >= 0 && y <= height)
		    {                                                                    
		      buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		      buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		      buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		    }
		}
	    }
	  else
	    {
	      for (int i = 0; i < (int)(xend - xstart); i++)
		{
		  int x = (int)(xstart + i + 0.5);
		  int y = (int)(ystart + m*i + 0.5);
		  int index = 3*(x + y*width);
		  if (x >= 0 && x <= width && y >= 0 && y <= height)
		    {
		      buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		      buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		      buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		    }
		}
	    }
	}
      else
	{
	  if (ystart > yend)
	    {
	      for (int j = 0; j < (int)(ystart - yend); j++)
		{
		  int x = (int)(xend + (double)(j)/m + 0.5);
		  int y = (int)(yend + j + 0.5);
		  int index = 3*(x + y*width);
		  if (x >= 0 && x <= width && y >= 0 && y <= height)
		    {
		      buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		      buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		      buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		    }
		}
	    }
	  else
	    {
	      for (int j = 0; j < (int)(yend - ystart); j++)
		{
		  int x = (int)(xstart + (double)(j)/m + 0.5);
		  int y = (int)(ystart + j + 0.5);
		  int index = 3*(x + y*width);
		  if (x >= 0 && x <= width && y >= 0 && y <= height)
		    {
		      buffer[index + 0] = (int)(red*alpha)   + (int)((1. - alpha)*(double)buffer[index + 0]);
		      buffer[index + 1] = (int)(green*alpha) + (int)((1. - alpha)*(double)buffer[index + 1]);
		      buffer[index + 2] = (int)(blue*alpha)  + (int)((1. - alpha)*(double)buffer[index + 2]);
		    }
		}
	    }
	}
    }
  return true;
}


unsigned char* convolve(unsigned char *image, float *filter, int w, int h, int fw, int fh)
{ 
  int rx = fw/2;
  int ry = fh/2;
  //allocate memory in interleaved rgb format, raster scan order row major
  unsigned char* outBuffer = (unsigned char*)malloc(sizeof(unsigned char)*3*w*h);
  for (int j = 0; j < h; j++)
    {
      for (int i = 0; i < w; i++)
	{
	  int index = 3*(i + j*w);
	  float red = 0;
	  float green = 0;
	  float blue = 0;
	  float accum = 0;
	  for (int fj = -ry; fj <= ry; fj++)
	    {
	      for (int fi = -rx; fi <= rx; fi++)
		{
		  int _i = fi + i;
		  int _j = fj + j;
		  if (_i < 0 || _i >= w || _j < 0 || _j >= h)
		    {
		      continue;
		    }

		  int indexFilter = (fi + rx) + fw*(fj + ry);
		  int indexInput = 3*(_i + _j*w);
		  red += (float)(image[indexInput + 0])/255.0*(filter[indexFilter]);
		  green += (float)(image[indexInput + 1])/255.0*(filter[indexFilter]);
		  blue += (float)(image[indexInput + 2])/255.0*(filter[indexFilter]);
		  accum += filter[indexFilter];
		}
	    }
	  if (accum == 0)
	    {
	      outBuffer[index + 0] = 0;
	      outBuffer[index + 1] = 0;
	      outBuffer[index + 2] = 0;
	    }
	  else
	    {
	      outBuffer[index + 0] = (unsigned char)(clamp((int)(red/accum*255.f + 0.5)));
	      outBuffer[index + 1] = (unsigned char)(clamp((int)(green/accum*255.f + 0.5)));
	      outBuffer[index + 2] = (unsigned char)(clamp((int)(blue/accum*255.f + 0.5)));
	    }
	}
    }
  return outBuffer;
}
