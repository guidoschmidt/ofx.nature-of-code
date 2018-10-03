#pragma once

#include "ofMain.h"
#include "Mover.hpp"

class Attractor {
private:
  float _mass;
  glm::vec2 _position;
  float _G;

public:
  Attractor();
  glm::vec2 attract(Mover* mover);
  void display();

  glm::vec2 getPosition();
};
