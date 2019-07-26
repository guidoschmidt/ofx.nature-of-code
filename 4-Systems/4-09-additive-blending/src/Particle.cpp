#include "Particle.hpp"

Particle::Particle(glm::vec2 location, ofImage* sprite) {
  _mass = 200.0f;
  _position = location;
  _velocity = glm::vec2(ofRandom(-1, 1), ofRandom(-1, 0));
  _acceleration = glm::vec2(0, 0.005);
  _lifespan = 300.0;
  _sprite = sprite;
}

void Particle::run() {
  update();
  display();
}

void Particle::applyForce(glm::vec2 force) {
  force /= _mass;
  _acceleration += force;
}

void Particle::update() {
  _velocity += _acceleration;
  _position += _velocity;
  _lifespan -= 0.1;
}

void Particle::display() {
  _sprite->draw(_position.x - _sprite->getWidth() / 2,
                _position.y - _sprite->getHeight() / 2);
}

bool Particle::isDead() {
  if (_lifespan < 0.0) { return true; }
  else { return false; }
}
