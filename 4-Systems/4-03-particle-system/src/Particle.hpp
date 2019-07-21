#pragma once

#include "ofMain.h"

class Particle {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _lifespan;

public:
  Particle(glm::vec2 location);
  void run();
  void update();
  void display();
  bool isDead();
};
