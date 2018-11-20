#pragma once

#include "ofMain.h"

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _mass;
  float _damping;
  glm::vec2 _dragOffset;
  bool _dragging;

public:

  Mover(float x, float y);
  void update();
  void applyForce(glm::vec2 force);
  void display();
  void clicked(int mx, int my);
  void stopDragging();
  void drag(int mx, int my);

  void setPosition(glm::vec2 pos);
  void setVelocity(glm::vec2 vel);

  glm::vec2 getPosition();
  glm::vec2 getVelocity();
};
