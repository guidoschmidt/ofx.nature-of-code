#pragma once

#include <vector>
#include <string>
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem
{
private:
  glm::vec2              _origin;
  std::vector<Particle*> _particles;
  std::vector<ofImage>*  _textures;

public:
  ParticleSystem(glm::vec2 position, std::vector<ofImage>& textures);
  void addParticle();
  void run();
  void applyForce(glm::vec2 force);
  bool isDead();
};
