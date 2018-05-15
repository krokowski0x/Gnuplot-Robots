#include <iomanip>
#include <fstream>
#include "Vector2D.hh"
#include "Path.hh"

void Path::setStart(Vector2D s)
{
  start = s;
}

void Path::setEnd(Vector2D e)
{
  end = e;
}

Vector2D Path::getStart()
{
  return start;
}

Vector2D Path::getEnd()
{
  return end;
}

bool Path::drawToFile(const char *sFile)
{
  ofstream fileStrm;

  fileStrm.open(sFile, std::ios::out | std::ios::app);
  if(!fileStrm.is_open()) {
    cerr << "Opening file \"" << sFile << "\"" << std::endl
    << " failed." << std::endl;
    return false;
  }

  fileStrm << setw(16) << fixed << setprecision(10) << start;
  fileStrm << setw(16) << fixed << setprecision(10) << end;

  fileStrm.close();
  return !fileStrm.fail();
}
