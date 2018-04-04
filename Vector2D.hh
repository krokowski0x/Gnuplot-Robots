#ifndef VECTOR2D_HH
#define VECTOR2D_HH

#include <iostream>
#include "Matrix2x2.hh"

using namespace std;

class Wektor2D {

  double x,y;

public:
  void setX (double a);
  void setY (double a);
  double getX();
  double getY();
  bool drawToFile(const char *sFile);
};

Wektor2D operator + (Wektor2D &wek1, Wektor2D &wek2);
Wektor2D operator - (Wektor2D &wek1, Wektor2D &wek2);
Wektor2D operator * (Wektor2D &wek, Macierz2x2 &mac);
Wektor2D operator * (Wektor2D &wek, double a);
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);
std::ostream& operator << (std::ostream &Strm, Wektor2D &Wek);

#endif
