#pragma once

#include <vector>
#include <string>
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem
{
private:
  glm::vec2 _origin;
  std::vector<Particle*> _particles;

  ofColor _particleColor;
  ofColor _particleColorIntesecting;

public:
  ParticleSystem(glm::vec2 position);
  void addParticle(glm::vec2 atPosition);
  void run();
  void applyForce(glm::vec2 force);
  void calculateIntersections();

  inline void setParticleColor(ofColor c) { _particleColor = ofColor(c.r, c.g, c.b); }
  inline void setParticleIntersectionColor(ofColor c) { _particleColorIntesecting = ofColor(c.r, c.g, c.b); }
};
