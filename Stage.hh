#ifndef STAGE_HH
#define STAGE_HH

#include <iostream>
#include <fstream>
#include "Rectangle.hh"
#include "Robot2D.hh"

class Stage {

  Rectangle rect1,rect2,rect3;
  robot r1,r2,r3;

public:

  void set(Rectangle &RECT1, Rectangle &RECT2, Rectangle &RECT3,
	   robot &R1, robot &R2, robot &R3);
  void setP (int i, Rectangle &p);
  void setR (int i, robot &r);
  Rectangle getP (int i);
  robot getR (int i);
};

#endif
