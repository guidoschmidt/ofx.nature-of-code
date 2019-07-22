#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(glm::vec2 position)
{
  _origin = position;
}

void ParticleSystem::addParticle()
{
  _particles.push_back(new Particle(_origin));
}

void ParticleSystem::run()
{
  for (int i = 0; i < _particles.size(); i++) {
    Particle* p = _particles.at(i);
    p->run();
    if (p->isDead()) {
      _particles.erase(_particles.begin() + i);
    }
  }
}
