#pragma once

#include "ofMain.h"

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _mass;

public:
  Mover(float mass = 1.0f, int x = 0, int y = 0);
  const float getMass();
  void applyForce(const glm::vec2 force);
  void update();
  void display();
  void checkEdges();
};
