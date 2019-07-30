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

public:
  ParticleSystem(glm::vec2 position);
  void addParticle(glm::vec2 atPosition);
  void run();
  void applyForce(glm::vec2 force);
  void calculateIntersections();
};
