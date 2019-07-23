#pragma once

#include "ofMain.h"

class Particle {
protected:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _lifespan;
  float _mass;

public:
  Particle(glm::vec2 location);
  void run();
  void update();
  void applyForce(glm::vec2 force);
  virtual void display();
  bool isDead();
};
