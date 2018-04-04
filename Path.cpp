#include <iomanip>
#include <fstream>
#include "Vector2D.hh"
#include "Path.hh"

void Sciezka::setStart(Wektor2D s)
{
  start = s;
}

void Sciezka::setEnd(Wektor2D e)
{
  end = e;
}

Wektor2D Sciezka::getStart()
{
  return start;
}

Wektor2D Sciezka::getEnd()
{
  return end;
}

bool Sciezka::drawToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile, std::ios::out | std::ios::app);
  if(!fileStrm.is_open()) {
    cerr << "Operacja otwarcia do zapisu \"" << sFile << "\"" << std::endl
    << " nie powiodla sie." << std::endl;
    return false;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << start;
  fileStrm << setw(16) << fixed << setprecision(10) << end;

  fileStrm.close();
  return !fileStrm.fail();
}
