#include "ParticleSystem.hpp"
#include <iostream>

ParticleSystem::ParticleSystem(glm::vec2 position)
{
  _origin = position;
}

void ParticleSystem::addParticle()
{
  float random = ofRandom(1.0);
  if (random < 0.5)
    _particles.push_back(new Particle(_origin));
  else
  _particles.push_back(new Confetti(_origin));
}

void ParticleSystem::run(glm::vec2 position)
{
  _origin = position;
  for (int i = 0; i < _particles.size(); i++) {
    Particle* p = _particles.at(i);
    p->run();
    if (p->isDead()) {
      _particles.erase(_particles.begin() + i);
    }
  }
}
