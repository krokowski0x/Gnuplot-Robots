#ifndef MATRIX2X2_HH
#define MATRIX2X2_HH

#include <iostream>

class Macierz2x2 {

  double tab[2][2];

  public:
  void set(double a, double b,
 	   double c, double d);
  double get(int i, int j);
};

#endif
