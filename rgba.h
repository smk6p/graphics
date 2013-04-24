#ifndef __RGBA_H__
#define __RGBA_H__

class RGBA {
public:
  
  RGBA();
  ~RGBA();

  void setRed(float _r);
  void setRed(unsigned char _r);

private:

  float r;
  float g;
  float b;
  float a;

};


#endif
