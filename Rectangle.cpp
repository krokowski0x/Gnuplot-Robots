#include <iomanip>
#include <fstream>
#include "Rectangle.hh"
#include "Vector2D.hh"
#include "Matrix2x2.hh"

Vector2D& Rectangle::operator [] (const int i)
{
  switch(i){
  case 1:
    return v1;
    break;
  case 2:
    return v2;
    break;
  case 3:
    return v3;
    break;
  case 4:
    return v4;
    break;
  }
  return v1;
}


void Rectangle::equal()
{
  if (pow(w1.getX() - w2.getX(),2) + pow(w1.getY() - w2.getY(),2) ==
      pow(w3.getX() - w4.getX(),2) + pow(w3.getY() - w4.getY(),2)){
    cout << "Longer sides are equal!" << endl;
  } else {
    cout << "WARNING! Longer sides are NOT equal!" << endl;
  }
  if (pow(w1.getX() - w3.getX(),2) + pow(w1.getY() - w3.getY(),2) ==
      pow(w2.getX() - w4.getX(),2) + pow(w2.getY() - w4.getY(),2)){
    cout << "Shorter sides are equal!" << endl << endl;
  } else {
    cout << "WARNING! Shorter sides are NOT equal!" << endl << endl;
  }
}

Rectangle operator + (Rectangle &r, Vector2D &vec)
{
  r[1] = r[1]+vec;
  r[2] = r[2]+vec;
  r[3] = r[3]+vec;
  r[4] = r[4]+vec;
  return r;
}

Rectangle operator * (Rectangle &r, Marix2x2 &m)
{
  r[1] = r[1]*m;
  r[2] = r[2]*m;
  r[3] = r[3]*m;
  r[4] = r[4]*m;
  return r;
}

std::ostream& operator << (std::ostream &Strm, Rectangle &Rect)
{
  Strm << Rect[1].getX() << "\t" << Rect[1].getY() << std::endl;
  Strm << Rect[2].getX() << "\t" << Rect[2].getY() << std::endl;
  Strm << Rect[3].getX() << "\t" << Rect[3].getY() << std::endl;
  Strm << Rect[4].getX() << "\t" << Rect[4].getY() << std::endl;
  return Strm;
}

bool Rectangle::drawToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile);
  if(!fileStrm.is_open()) {
    cerr << "Opening file \"" << sFile << "\"" << std::endl
    << " failed." << std::endl;
    return false;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << v1;
  fileStrm << setw(16) << fixed << setprecision(10) << v2;
  fileStrm << setw(16) << fixed << setprecision(10) << v3;
  fileStrm << setw(16) << fixed << setprecision(10) << v4;
  fileStrm << setw(16) << fixed << setprecision(10) << v1;

  fileStrm.close();
  return !fileStrm.fail();
}

void Init (double x, double y, double s, Rectangle &r)
{
  r.setSide(s);

  r[1].setX(x);       r[1].setY(y);
  r[2].setX(x+(2*s)); r[2].setY(y);
  r[3].setX(x+(2*s)); r[3].setY(y+s);
  r[4].setX(x);       r[4].setY(y+s);
}
