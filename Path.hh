#ifndef PATH_HH
#define PATH_HH

#include <iostream>
#include <fstream>
#include "Vector2D.hh"

class Path : public Vector2D {

  Vector2D start, end;

public:

  void setStart(Vector2D s);
  void setEnd(Vector2D e);
  Vector2D getStart();
  Vector2D getEnd();
  bool drawToFile (const char *sFile);
};

#endif
