#pragma once

#include "ofMain.h"
#include "Mover.hpp"

class Liquid {
private:
  float _x, _y, _w, _h;
  float _c;
public:
  Liquid(float x, float y, float w, float h, float c);
  const bool contains(Mover *m);
  const glm::vec2 drag(Mover *m);
  const void display();
};
