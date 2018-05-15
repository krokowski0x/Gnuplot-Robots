#include <iostream>
#include <fstream>
#include "Rectangle.hh"
#include "Robot2D.hh"
#include "Stage.hh"

void Stage::set (Rectangle &RECT1, Rectangle &RECT2, Rectangle &RECT3,
		 robot &R1, robot &R2, robot &R3)
{
  p1 = RECT1; p2 = RECT2; p3 = RECT3;
  r1 = R1; r2 = R2; r3 = R3;
}

void Stage::setRECT (int i, Rectangle &r)
{
  switch(i) {
  case 1:
    rect1 = rect;
    break;
  case 2:
    rect2 = rect;
    break;
  case 3:
    rect3 = rect;
    break;
  }
}

void Stage::setR (int i, robot &r)
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

Rectangle Stage::getRECT (int i)
{
  switch(i) {
  case 1:
    return rect1;
    break;
  case 2:
    return rect2;
    break;
  case 3:
    return rect3;
    break;
  }
  return rect1;
}

robot Stage::getR (int i)
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
