#include "Mover.hpp"

Mover::Mover(float mass, int x, int y) {
  this->_position = glm::vec2(x, y);
  this->_velocity = glm::vec2(0, 0);
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
  ofSetColor(242, this->_mass * 60.0, 128);
  float size = this->_mass * 16.0f;
  ofDrawEllipse(this->_position, size, size);
}

void Mover::checkEdges() {
  if (this->_position.x > ofGetWidth()) {
    this->_position.x = ofGetWidth();
    this->_velocity.x *= -1;
  } else if (this->_position.x < 0) {
    this->_position.x = 0;
    this->_velocity.x *= -1;
  }

  if (this->_position.y > ofGetHeight()) {
    this->_position.y = ofGetHeight();
    this->_velocity.y *= -1;
  }
}

const float Mover::getMass() {
  return this->_mass;
}
