#pragma once

#include "ofMain.h"

class Particle {
protected:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _lifespan;
  float _mass;
  bool _overlap;
  float _highlight;
  float _radius;

public:
  Particle(glm::vec2 location);
  void run();
  void update();
  void applyForce(glm::vec2 force);
  virtual void display();
  bool isDead();
  void intersects(std::vector<Particle*> particles);

  inline glm::vec2 getPosition() { return _position; }
  inline float getRadius() { return _radius; }
};
