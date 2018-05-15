#ifndef VECTOR2D_HH
#define VECTOR2D_HH

#include <iostream>
#include "Matrix2x2.hh"

using namespace std;

class Vector2D {

  double x,y;

public:
  void setX (double a);
  void setY (double a);
  double getX();
  double getY();
  bool drawToFile(const char *sFile);
};

Vector2D operator + (Vector2D &vec1, Vector2D &vec2);
Vector2D operator - (Vector2D &vec1, Vector2D &vec2);
Vector2D operator * (Vector2D &vec, Matrix2x2 &m);
Vector2D operator * (Vector2D &vec, double a);
std::istream& operator >> (std::istream &Strm, Vector2D &Vec);
std::ostream& operator << (std::ostream &Strm, Vector2D &Vec);

#endif
