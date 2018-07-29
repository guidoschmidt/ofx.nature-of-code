#pragma once

#include "ofMain.h"

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;

public:
  Mover();
  ~Mover();
  void update();
  void display();
  void checkEdges();
};
