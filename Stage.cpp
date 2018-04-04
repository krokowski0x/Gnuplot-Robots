#include <iostream>
#include <fstream>
#include "Rectangle.hh"
#include "Robot2D.hh"
#include "Stage.hh"

void Scena::set (Prostokat &P1, Prostokat &P2, Prostokat &P3,
		 robot &R1, robot &R2, robot &R3)
{
  p1 = P1; p2 = P2; p3 = P3;
  r1 = R1; r2 = R2; r3 = R3;
}

void Scena::setP (int i, Prostokat &p)
{
  switch(i) {
  case 1:
    p1 = p;
    break;
  case 2:
    p2 = p;
    break;
  case 3:
    p3 = p;
    break;
  }
}

void Scena::setR (int i, robot &r)
{
  switch(i) {
  case 1:
    r1 = r;
    break;
  case 2:
    r2 = r;
    break;
  case 3:
    r3 = r;
    break;
  }
}

Prostokat Scena::getP (int i)
{
  switch(i) {
  case 1:
    return p1;
    break;
  case 2:
    return p2;
    break;
  case 3:
    return p3;
    break;
  }
  return p1;
}

robot Scena::getR (int i)
{
  switch(i) {
  case 1:
    return r1;
    break;
  case 2:
    return r2;
    break;
  case 3:
    return r3;
    break;
  }
  return r1;
}
