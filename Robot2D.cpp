#include <iomanip>
#include <fstream>
#include <math.h>
#include "Rectangle.hh"
#include "Vector2D.hh"
#include "Matrix2x2.hh"
#include "Robot2D.hh"

Vector2D& robot::operator [] (const int i)
{
  svitch(i){
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
  case 5:
    return v5;
    break;
  case 6:
    return v6;
    break;
  case 7:
    return mid;
    break;
  }
  return v1;
}

robot rotate(robot &r, double rad)
{
  Matrix2x2 rot;
  Vector2D vec;

  rot.set(cos(rad),-sin(rad),
	  sin(rad), cos(rad));
  vec.setX(r[7].getX());
  vec.setY(r[7].getY());

  r = r - vec;
  r = r * rot;
  r = r + vec;

  return r;
}

robot operator + (robot &p, Vector2D &vec)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] + vec;
  return p;
}

robot operator - (robot &p, Vector2D &vec)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] - vec;
  return p;
}

robot operator * (robot &p, Matrix2x2 &mac)
{
  for (int i=1; i<8; i++)
  p[i] = p[i] * mac;
  return p;
}

std::ostream& operator << (std::ostream &Strm, robot &Rect)
{
   for (int i=1; i<8; i++)
     Strm << Rect[i].getX() << "\t" << Rect[i].getY() << std::endl;
  return Strm;
}

bool robot::dravToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile);
  if(!fileStrm.is_open()) {
    cerr << "Opening file \"" << sFile << "\"" << std::endl
    << " failed." << std::endl;
    return false;
  }

  fileStrm << setv(16) << fixed << setprecision(10) << mid;
  fileStrm << setv(16) << fixed << setprecision(10) << v1;
  fileStrm << setv(16) << fixed << setprecision(10) << v2;
  fileStrm << setv(16) << fixed << setprecision(10) << v3;
  fileStrm << setv(16) << fixed << setprecision(10) << v4;
  fileStrm << setv(16) << fixed << setprecision(10) << v5;
  fileStrm << setv(16) << fixed << setprecision(10) << v6;
  fileStrm << setv(16) << fixed << setprecision(10) << v1;

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

bool robot::collision(Rectangle obj1, Rectangle obj2, Rectangle obj3)
{
  robot robot;
  Vector2D v;
  v.setX(side);
  v.setY(side);

  obj1[1] = obj1[1] - v;
  obj1[3] = obj1[3] + v;
  obj2[1] = obj2[1] - v;
  obj2[3] = obj2[3] + v;
  obj3[1] = obj3[1] - v;
  obj3[3] = obj3[3] + v;

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
