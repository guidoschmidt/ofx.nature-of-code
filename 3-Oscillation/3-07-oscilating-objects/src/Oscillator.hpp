#pragma once

#include "ofMain.h"

class Oscillator {
private:
  glm::vec2 _angle;
  glm::vec2 _velocity;
  glm::vec2 _amplitude;
  glm::vec3 _color;

public:
  Oscillator();
  void oscillate();
  void display();
};
