#include <iomanip>
#include <fstream>
#include "Rectangle.hh"
#include "Vector2D.hh"
#include "Matrix2x2.hh"

Wektor2D& Prostokat::operator [] (const int i)
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
  }
  return w1;
}


void Prostokat::equal()
{
  if (pow(w1.getX() - w2.getX(),2) + pow(w1.getY() - w2.getY(),2) ==
      pow(w3.getX() - w4.getX(),2) + pow(w3.getY() - w4.getY(),2)){
    cout << "Dluzsze boki sa sobie rowne!" << endl;
  } else {
    cout << " UWAGA! Dluzsze boki nie sa sobie rowne!" << endl;
  }
  if (pow(w1.getX() - w3.getX(),2) + pow(w1.getY() - w3.getY(),2) ==
      pow(w2.getX() - w4.getX(),2) + pow(w2.getY() - w4.getY(),2)){
    cout << "Krotsze boki sa sobie rowne!" << endl << endl;
  } else {
    cout << " UWAGA! Krotsze boki nie sa sobie rowne!" << endl << endl;
  }
}

Prostokat operator + (Prostokat &p, Wektor2D &wek)
{
  p[1] = p[1]+wek;
  p[2] = p[2]+wek;
  p[3] = p[3]+wek;
  p[4] = p[4]+wek;
  return p;
}

Prostokat operator * (Prostokat &p, Macierz2x2 &mac)
{
  p[1] = p[1]*mac;
  p[2] = p[2]*mac;
  p[3] = p[3]*mac;
  p[4] = p[4]*mac;
  return p;
}

std::ostream& operator << (std::ostream &Strm, Prostokat &Pros)
{
  Strm << Pros[1].getX() << "\t" << Pros[1].getY() << std::endl;
  Strm << Pros[2].getX() << "\t" << Pros[2].getY() << std::endl;
  Strm << Pros[3].getX() << "\t" << Pros[3].getY() << std::endl;
  Strm << Pros[4].getX() << "\t" << Pros[4].getY() << std::endl;
  return Strm;
}

bool Prostokat::drawToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile);
  if(!fileStrm.is_open()) {
    cerr << "Operacja otwarcia do zapisu \"" << sFile << "\"" << std::endl
    << " nie powiodla sie." << std::endl;
    return false;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << w1;
  fileStrm << setw(16) << fixed << setprecision(10) << w2;
  fileStrm << setw(16) << fixed << setprecision(10) << w3;
  fileStrm << setw(16) << fixed << setprecision(10) << w4;
  fileStrm << setw(16) << fixed << setprecision(10) << w1;

  fileStrm.close();
  return !fileStrm.fail();
}

void Init (double x, double y, double s, Prostokat &p)
{
  p.setSide(s);

  p[1].setX(x);       p[1].setY(y);
  p[2].setX(x+(2*s)); p[2].setY(y);
  p[3].setX(x+(2*s)); p[3].setY(y+s);
  p[4].setX(x);       p[4].setY(y+s);

}
