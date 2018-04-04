#include <iomanip>
#include <fstream>
#include <math.h>
#include "Rectangle.hh"
#include "Vector2D.hh"
#include "Matrix2x2.hh"
#include "Robot2D.hh"

Wektor2D& robot::operator [] (const int i)
{
  switch(i){
  case 1:
    return w1;
    break;
  case 2:
    return w2;
    break;
  case 3:
    return w3;
    break;
  case 4:
    return w4;
    break;
  case 5:
    return w5;
    break;
  case 6:
    return w6;
    break;
  case 7:
    return mid;
    break;
  }
  return w1;
}

robot rotate(robot &r, double rad)
{
  Macierz2x2 rot;
  Wektor2D wek;

  rot.set(cos(rad),-sin(rad),
	  sin(rad), cos(rad));
  wek.setX(r[7].getX());
  wek.setY(r[7].getY());

  r = r - wek;
  r = r * rot;
  r = r + wek;

  return r;
}

robot operator + (robot &p, Wektor2D &wek)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] + wek;
  return p;
}

robot operator - (robot &p, Wektor2D &wek)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] - wek;
  return p;
}

robot operator * (robot &p, Macierz2x2 &mac)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] * mac;
  return p;
}

std::ostream& operator << (std::ostream &Strm, robot &Pros)
{
   for (int i=1; i<8; i++)
     Strm << Pros[i].getX() << "\t" << Pros[i].getY() << std::endl;
  return Strm;
}

bool robot::drawToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile);
  if(!fileStrm.is_open()) {
    cerr << "Operacja otwarcia do zapisu \"" << sFile << "\"" << std::endl
    << " nie powiodla sie." << std::endl;
    return false;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << mid;
  fileStrm << setw(16) << fixed << setprecision(10) << w1;
  fileStrm << setw(16) << fixed << setprecision(10) << w2;
  fileStrm << setw(16) << fixed << setprecision(10) << w3;
  fileStrm << setw(16) << fixed << setprecision(10) << w4;
  fileStrm << setw(16) << fixed << setprecision(10) << w5;
  fileStrm << setw(16) << fixed << setprecision(10) << w6;
  fileStrm << setw(16) << fixed << setprecision(10) << w1;

  fileStrm.close();
  return !fileStrm.fail();
}

void Init(double x, double y, double s, robot &robot)
{
  robot.setSide(s);

  robot[7].setX(x);       robot[7].setY(y);
  robot[1].setX(x+s);     robot[1].setY(y);
  robot[2].setX(x+(s/2)); robot[2].setY(y+((s*sqrt(3))/2));
  robot[3].setX(x-(s/2)); robot[3].setY(y+((s*sqrt(3))/2));
  robot[4].setX(x-s);     robot[4].setY(y);
  robot[5].setX(x-(s/2)); robot[5].setY(y-((s*sqrt(3))/2));
  robot[6].setX(x+(s/2)); robot[6].setY(y-((s*sqrt(3))/2));
}

bool robot::collision(Prostokat obj1, Prostokat obj2, Prostokat obj3)
{
  robot robot;
  Wektor2D w;
  w.setX(side);
  w.setY(side);

  obj1[1] = obj1[1] - w;
  obj1[3] = obj1[3] + w;
  obj2[1] = obj2[1] - w;
  obj2[3] = obj2[3] + w;
  obj3[1] = obj3[1] - w;
  obj3[3] = obj3[3] + w;

  if (robot[7].getX() > obj1[1].getX() &&
      robot[7].getX() < obj1[3].getX() &&
      robot[7].getY() > obj1[1].getY() &&
      robot[7].getY() < obj1[3].getY())
  return true;

  else if (robot[7].getX() > obj2[1].getX() &&
      robot[7].getX() < obj2[3].getX() &&
      robot[7].getY() > obj2[1].getY() &&
      robot[7].getY() < obj2[3].getY())
  return true;

  else if (robot[7].getX() > obj2[1].getX() &&
      robot[7].getX() < obj2[3].getX() &&
      robot[7].getY() > obj2[1].getY() &&
      robot[7].getY() < obj2[3].getY())
  return true;

  else
    return false;
}
