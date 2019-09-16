#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(glm::vec2 position, std::vector<ofImage>& textures)
{
  _origin = position;
  _textures = &textures;
}

void ParticleSystem::addParticle()
{
  int randomIndex = int(ofRandom(_textures->size()));
  ofImage *sprite = &(_textures->at(randomIndex));
  _particles.push_back(new Particle(_origin, sprite));
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

void ParticleSystem::applyForce(glm::vec2 force) {
  for (Particle *p : _particles) {
    p->applyForce(force);
  }
}

bool ParticleSystem::isDead() {
  if (_particles.size() == 0) {
    return true;
  } else {
    return false;
  }
}
