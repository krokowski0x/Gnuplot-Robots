#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include <iostream>
#include <math.h>
#include "Vector2D.hh"
#include "Matrix2x2.hh"

using namespace std;

class Prostokat : public Wektor2D {

  Wektor2D w1,w2,w3,w4;
  double side;

public:
  Prostokat() {}
  Prostokat(const Prostokat &) {}
  ~Prostokat() {}
  Wektor2D& operator [] (const int i);
  void equal();  // Sprawdza czy boki sa rowne
  Prostokat operator * (double a);
  bool drawToFile (const char *sFile);
  Prostokat obrot();
  void setSide (double s) { side = s; }
  double getSide() { return side; }
};

void Init (double x, double y, double s, Prostokat &p);
Prostokat operator + (Prostokat &p, Wektor2D &wek);
Prostokat operator * (Prostokat &p, Macierz2x2 &mac);
std::ostream& operator << (std::ostream &Strm, Prostokat &Pros);

#endif
