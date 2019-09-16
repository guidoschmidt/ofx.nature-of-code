#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(glm::vec2 position)
{
  _origin = position;
}

void ParticleSystem::addParticle(glm::vec2 atPosition)
{
  glm::vec2 offset = glm::vec2(ofRandom(-25.0f, 25.0f),
                               ofRandom(-25.0f, 25.0f));
  _particles.push_back(new Particle(atPosition + offset));
}

void ParticleSystem::run()
{
  for (int i = 0; i < _particles.size(); i++) {
    Particle* p = _particles.at(i);
    p->setColor(_particleColor);
    p->setIntersectionColor(_particleColorIntesecting);
    p->run();
    if (p->isDead()) {
      _particles.erase(_particles.begin() + i);
    }
  }
}

void ParticleSystem::applyForce(glm::vec2 force) {
  for (Particle *p : _particles) {
    p->applyForce(force);
  }
}

void ParticleSystem::calculateIntersections() {
  for (auto* p : _particles) {
    p->intersects(_particles);
  }
}
