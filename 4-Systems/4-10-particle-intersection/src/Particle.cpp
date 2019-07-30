#include "Particle.hpp"

Particle::Particle(glm::vec2 location) {
  _highlight = false;
  _mass = 20.0f;
  _position = location;
  _velocity = glm::vec2(ofRandom(-1, 1), ofRandom(-1, 0));
  _acceleration = glm::vec2(0, 0.005);
  _lifespan = 600.0;
  _radius = 10.0f;
  _color = ofColor(255, 0, 0);
  _intersectionColor = ofColor(0, 255, 0);
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
  _lifespan -= 1.5;
  _radius -= 0.05;
  if (_radius <= 0) _lifespan = 0.0f;
}

void Particle::display() {
  ofSetLineWidth(2);
  ofFill();
  if (_highlight > 0.0f) {
    ofSetColor(_color.lerp(_intersectionColor, _highlight),
               _lifespan);
  } else {
    ofSetColor(_color.r,
               _color.g,
               _color.b,
               _lifespan);
  }
  ofDrawEllipse(_position.x, _position.y, _radius, _radius);
}

bool Particle::isDead() {
  if (_lifespan < 0.0) { return true; }
  else { return false; }
}

void Particle::intersects(std::vector<Particle*> particles) {
  for (auto* other : particles) {
    if (other != this) {
      float distance = glm::distance2(_position,
                                      other->getPosition());
      if (distance < _radius + other->getRadius()) {
        _highlight = ofMap(distance, 0, _radius + other->getRadius(), 0.0f, 1.0f);
      }
    }
  }
}
