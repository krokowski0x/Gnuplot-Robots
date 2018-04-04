#ifndef STAGE_HH
#define STAGE_HH

#include <iostream>
#include <fstream>
#include "Rectangle.hh"
#include "Robot2D.hh"

class Scena {

  Prostokat p1,p2,p3;
  robot r1,r2,r3;

public:

  void set(Prostokat &P1, Prostokat &P2, Prostokat &P3,
	   robot &R1, robot &R2, robot &R3);
  void setP (int i, Prostokat &p);
  void setR (int i, robot &r);
  Prostokat getP (int i);
  robot getR (int i);
};

#endif
