#ifndef ROBOT2D_HH
#define ROBOT2D_HH

#include <iostream>
#include "Wektor2D.hh"
#include "Prostokat.hh"
#include "Macierz2x2.hh"

class robot : public Prostokat {

  Wektor2D w1,w2,w3,w4,w5,w6,mid;
  double side;

public:

  Wektor2D& operator [] (const int i);
  bool drawToFile (const char *sFile);
  void setSide (double s) { side = s; }
  double getSide() { return side; }
  bool collision(Prostokat obj1, Prostokat obj2, Prostokat obj3);
};

void Init(double x, double y, double s, robot &robot);
robot rotate (robot &r, double rad);
robot operator + (robot &p, Wektor2D &wek);
robot operator - (robot &p, Wektor2D &wek);
robot operator * (robot &p, Macierz2x2 &mac);
std::ostream& operator << (std::ostream &Strm, robot &p);

#endif
