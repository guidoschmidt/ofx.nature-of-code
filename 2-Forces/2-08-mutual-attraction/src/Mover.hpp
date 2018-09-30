#pragma once

#include "ofMain.h"

class Mover {
private:
  float _mass;
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  glm::vec3 _color;

public:
  Mover(float mass, float x, float y);
  void applyForce(glm::vec2 force);
  void update();
  void display();
  glm::vec2 attract(Mover* mover);

  float getMass();
  glm::vec2 getPosition();
  ofColor getColor();
};
