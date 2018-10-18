#pragma once

#include "ofMain.h"

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _topSpeed;
  double _xOff;
  double _yOff;
  float _r;

public:
  Mover();
  ~Mover();
  void update();
  void display();
  void checkEdges();
};
