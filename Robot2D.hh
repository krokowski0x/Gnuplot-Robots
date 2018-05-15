#ifndef ROBOT2D_HH
#define ROBOT2D_HH

#include <iostream>
#include "Vector2D.hh"
#include "Rectangle.hh"
#include "Matrix2x2.hh"

class robot : public Rectangle {

  Vector2D v1,v2,v3,v4,v5,v6,mid;
  double side;

public:

  Vector2D& operator [] (const int i);
  bool drawToFile (const char *sFile);
  void setSide (double s) { side = s; }
  double getSide() { return side; }
  bool collision(Rectangle obj1, Rectangle obj2, Rectangle obj3);
};

void Init(double x, double y, double s, robot &robot);
robot rotate (robot &r, double rad);
robot operator + (robot &p, Vector2D &vek);
robot operator - (robot &p, Vector2D &vek);
robot operator * (robot &p, Matrix2x2 &m);
std::ostream& operator << (std::ostream &Strm, robot &r);

#endif
