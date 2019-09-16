#include "Particle.hpp"

Particle::Particle(glm::vec2 location, ofImage* sprite) {
  _position = location;
  _velocity = glm::vec2(ofRandom(-1, 1), ofRandom(-1, 0));
  _acceleration = glm::vec2(0, 0);
  _lifespan = 255.0;
  _sprite = sprite;
}

void Particle::run() {
  update();
  render();
}

void Particle::applyForce(glm::vec2 force) {
  _acceleration += force;
}

void Particle::update() {
  _velocity += _acceleration;
  _position += _velocity;
  _acceleration *= 0;
  _lifespan -= 2.0;
}

void Particle::render() {
  ofSetColor(255, 255, 255, _lifespan);
  _sprite->draw(_position.x - _sprite->getWidth() / 2,
                _position.y - _sprite->getHeight() / 2);
}

bool Particle::isDead() {
  if (_lifespan < 0.0) { return true; }
  else { return false; }
}
