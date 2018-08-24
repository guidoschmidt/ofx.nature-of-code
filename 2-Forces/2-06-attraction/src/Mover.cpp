#include "Mover.hpp"

Mover::Mover(float mass, int x, int y) {
  this->_position = glm::vec2(x, y);
  this->_velocity = glm::vec2(0.001, 0.001);
  this->_acceleration = glm::vec2(0, 0);
  this->_mass = mass;
}

void Mover::applyForce(const glm::vec2 force) {
  glm::vec2 f = force / this->_mass;
  this->_acceleration += f;
}

void Mover::update() {
  this->_velocity += this->_acceleration;
  this->_position += this->_velocity;
  this->_acceleration *= 0.0;
}

void Mover::display() {
  ofSetColor(this->_mass,
             this->_mass,
             this->_mass);
  float size = this->_mass * 1.6f;
  ofDrawEllipse(this->_position, size, size);
}

void Mover::checkEdges() {
  if (this->_position.y > ofGetHeight()) {
    this->_velocity.y *= -0.9;
    this->_position.y = ofGetHeight();
  }
}

const float Mover::getMass() {
  return this->_mass;
}

glm::vec2 Mover::getVelocity() {
  return this->_velocity;
}

glm::vec2 Mover::getPosition() {
  return this->_position;
}
