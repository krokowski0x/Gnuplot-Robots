#ifndef PATH_HH
#define PATH_HH

#include <iostream>
#include <fstream>
#include "Vektor2D.hh"

class Sciezka : public Wektor2D {

  Wektor2D start,end;

public:

  void setStart(Wektor2D s);
  void setEnd(Wektor2D e);
  Wektor2D getStart();
  Wektor2D getEnd();
  bool drawToFile (const char *sFile);
};

#endif
