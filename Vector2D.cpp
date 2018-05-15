#include <fstream>
#include <iomanip>
#include <math.h>
#include "Vector2D.hh"
#include "Matrix2x2.hh"

void Vector2D::setX (double a)
{
  x = a;
}

void Vector2D::setY (double a)
{
  y = a;
}

double Vector2D::getX()
{
  return x;
}

double Vector2D::getY()
{
  return y;
}

bool Vector2D::drawToFile (const char *sFile)
{
  ofstream fileStrm;
  fileStrm.open("sFile");
  if(!fileStrm.is_open()){
    cerr << "Opening file \"" << sFile << "\"" << std::endl
	 << " failed." << std::endl;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << x;
  fileStrm << setw(16) << fixed << setprecision(10) << y;

  fileStrm.close();
  return !fileStrm.fail();
}

Vector2D operator + (Vector2D &vec1, Vector2D &vec2)
{
  Vector2D tmp;
  tmp.setX(vec1.getX() + vec2.getX());
  tmp.setY(vec1.getY() + vec2.getY());
  return tmp;
}

Vector2D operator - (Vector2D &vec1, Vector2D &vec2)
{
  Vector2D tmp;
  tmp.setX(vec1.getX() - vec2.getX());
  tmp.setY(vec1.getY() - vec2.getY());
  return tmp;
}

std::istream& operator >> (std::istream &Strm, Vector2D &Vec)
{
  double x,y;
  Strm >> x >> y;
  Vec.setX(x);
  Vec.setY(y);
  return Strm;
}

std::ostream& operator << (std::ostream &Strm, Vector2D &Vec)
{
  return Strm << Vec.getX() << "\t" << Vec.getY() << endl;
}

Vector2D operator * (Vector2D &vec, Matrixz2x2 &m)
{
  vec.setX( (vec.getX()*m.get(0,0)) + (vec.getY()*m.get(0,1)) );
  vec.setY( (vec.getX()*m.get(1,0)) + (vec.getY()*m.get(1,1)) );
  return vec;
}

Vector2D operator * (Vector2D &vec, double a)
{
  Vector2D tmp;
  tmp.setX(vec.getX()*a);
  tmp.setY(vec.getY()*a);
  return tmp;
}
