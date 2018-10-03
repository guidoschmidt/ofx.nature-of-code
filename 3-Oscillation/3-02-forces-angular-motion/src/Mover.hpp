#pragma once

#include "ofMain.h"

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  double _mass;

  double _angle;
  double _angularVelocity;
  double _angularAcceleration;

public:
  Mover(float mass, float x, float y);

  void applyForce(glm::vec2 force);
  void update();
  void display(double distance);

  glm::vec2 getPosition();
  double getMass();
};
