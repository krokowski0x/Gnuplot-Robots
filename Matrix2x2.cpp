#include "Matrix2x2.hh"

void Macierz2x2::set(double a, double b,
		     double c, double d)
{
  tab[0][0] = a; tab[0][1] = b;
  tab[1][0] = c; tab[1][1] = d;
}

double Macierz2x2::get(int i, int j)
{
  return tab[i][j];
}
