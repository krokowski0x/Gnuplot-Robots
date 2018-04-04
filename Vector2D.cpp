#include <fstream>
#include <iomanip>
#include <math.h>
#include "Vector2D.hh"
#include "Matrix2x2.hh"

void Wektor2D::setX (double a)
{
  x = a;
}

void Wektor2D::setY (double a)
{
  y = a;
}

double Wektor2D::getX()
{
  return x;
}

double Wektor2D::getY()
{
  return y;
}

bool Wektor2D::drawToFile (const char *sFile)
{
  ofstream fileStrm;
  fileStrm.open("sFile");
  if(!fileStrm.is_open()){
    cerr << "Operacja otwarcia do zapisu \"" << sFile << "\"" << std::endl
	 << "nie powiodla sie" << std::endl;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << x;
  fileStrm << setw(16) << fixed << setprecision(10) << y;

  fileStrm.close();
  return !fileStrm.fail();
}

Wektor2D operator + (Wektor2D &wek1, Wektor2D &wek2)
{
  Wektor2D tmp;
  tmp.setX(wek1.getX() + wek2.getX());
  tmp.setY(wek1.getY() + wek2.getY());
  return tmp;
}

Wektor2D operator - (Wektor2D &wek1, Wektor2D &wek2)
{
  Wektor2D tmp;
  tmp.setX(wek1.getX() - wek2.getX());
  tmp.setY(wek1.getY() - wek2.getY());
  return tmp;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
  double x,y;
  Strm >> x >> y;
  Wek.setX(x);
  Wek.setY(y);
  return Strm;
}

std::ostream& operator << (std::ostream &Strm, Wektor2D &Wek)
{
  return Strm << Wek.getX() << "\t" << Wek.getY() << endl;
}

Wektor2D operator * (Wektor2D &wek, Macierz2x2 &mac)
{
  wek.setX( (wek.getX()*mac.get(0,0)) + (wek.getY()*mac.get(0,1)) );
  wek.setY( (wek.getX()*mac.get(1,0)) + (wek.getY()*mac.get(1,1)) );
  return wek;
}

Wektor2D operator * (Wektor2D &wek, double a)
{
  Wektor2D tmp;
  tmp.setX(wek.getX()*a);
  tmp.setY(wek.getY()*a);
  return tmp;
}
