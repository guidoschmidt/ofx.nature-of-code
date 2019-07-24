#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class Repeller {
private:
  glm::vec2 _position;
  float _G;

public:
  Repeller(glm::vec2 origin);
  void display();
  glm::vec2 repel(Particle* p);

  inline void setPosition(glm::vec2 p) { _position = p; }
};
