#pragma once

#include "ofMain.h"

class Particle {
protected:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _lifespan;
  float _mass;
  ofImage* _sprite;

public:
  Particle(glm::vec2 location, ofImage* sprite);
  void run();
  void update();
  void applyForce(glm::vec2 force);
  virtual void display();
  bool isDead();

  inline glm::vec2 getPosition() { return _position; }
};
