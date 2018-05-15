#include "Matrix2x2.hh"

void Matrix2x2::set(double a, double b,
		     double c, double d)
{
  arr[0][0] = a; arr[0][1] = b;
  arr[1][0] = c; arr[1][1] = d;
}

double Matrix2x2::get(int i, int j)
{
  return arr[i][j];
}
