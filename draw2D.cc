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
