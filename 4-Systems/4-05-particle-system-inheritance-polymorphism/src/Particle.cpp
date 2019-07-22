#include "Particle.hpp"

Particle::Particle(glm::vec2 location) {
  _position = location;
  _velocity = glm::vec2(ofRandom(-1, 1), ofRandom(-1, 0));
  _acceleration = glm::vec2(0, 0.005);
  _lifespan = 200.0;
}

void Particle::run() {
  update();
  display();
}

void Particle::update() {
  _velocity += _acceleration;
  _position += _velocity;
  _lifespan -= 0.1;
}

void Particle::display() {
  ofSetColor(0, 0, 0, _lifespan);
  ofSetLineWidth(2);
  ofFill();
  ofDrawEllipse(_position.x, _position.y, 12, 12);
}

bool Particle::isDead() {
  if (_lifespan < 0.0) { return true; }
  else { return false; }
}
