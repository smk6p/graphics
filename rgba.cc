#include "rgba.h"

RGBA::RGBA()
{
  r = 0.0f;
  g = 0.0f;
  b = 0.0f;
  a = 1.0f;
}

RGBA::~RGBA()
{
}

void RGBA::setRed(float _r)
{
  r = _r;
}

void RGBA::setRed(unsigned char _r)
{
  r = (float)(_r)/255.0f;
}

void RGBA::setGreen(float _g)
{
  g = _g;
}

void RGBA::setGreen(unsigned char _g)
{
  g = _g;
}

void RGBA::setBlue(float _b)
{
  b = _b;
}

void RGBA::setBlue(float _b)
{
  b = _b;
}
