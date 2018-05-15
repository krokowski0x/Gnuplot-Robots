#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include <iostream>
#include <math.h>
#include "Vector2D.hh"
#include "Matrix2x2.hh"

using namespace std;

class Rectangle : public Vector2D {

  Vector2D v1,v2,v3,v4;
  double side;

public:
  Rectangle() {}
  Rectangle(const Rectangle &) {}
  ~Rectangle() {}
  Vector2D& operator [] (const int i);
  void equal();  // Checks if sides are equal
  Rectangle operator * (double a);
  bool drawToFile (const char *sFile);
  Rectangle rotate();
  void setSide (double s) { side = s; }
  double getSide() { return side; }
};

void Init (double x, double y, double s, Rectangle &r);
Rectangle operator + (Rectangle &r, Vector2D &v);
Rectangle operator * (Rectangle &r, Macierz2x2 &m);
std::ostream& operator << (std::ostream &Strm, Rectangle &Rect);

#endif
