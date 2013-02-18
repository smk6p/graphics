#ifndef __DRAW2D_H__
#define __DRAW2D_H__

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
	      double alpha);

bool isInsideCircle(double cx, double cy, double radius, double x, double y);

bool drawcirc(unsigned char *buffer,
	      int width,
	      int height,
	      double cx,
	      double cy,
	      double radius,
	      int red,
	      int green,
	      int blue,
	      double alpha);

#endif
