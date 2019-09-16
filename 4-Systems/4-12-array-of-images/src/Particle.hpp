#pragma once

#include "ofMain.h"

class Particle {
protected:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _lifespan;
  ofImage* _sprite;

public:
  Particle(glm::vec2 location, ofImage* sprite);
  void run();
  void update();
  void applyForce(glm::vec2 force);
  void render();
  bool isDead();

  inline glm::vec2 getPosition() { return _position; }
};
