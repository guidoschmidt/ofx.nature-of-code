#include "Mover.hpp"

Mover::Mover() {
  this->_position = glm::vec2(30, 30);
  this->_velocity = glm::vec2(0, 0);
  this->_acceleration = glm::vec2(0, 0);
  this->_mass = 1.0f;
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
  ofSetColor(242, 12, 128);
  ofDrawEllipse(this->_position, 48, 48);
}

void Mover::checkEdges() {
  if (this->_position.x > ofGetWidth()) {
    this->_position.x = ofGetWidth();
  } else if (this->_position.x < 0) {
    this->_position.x = 0;
  }

  if (this->_position.y > ofGetHeight()) {
    this->_position.y = ofGetHeight();
  } else if (this->_position.y < 0) {
    this->_position.y = 0;
  }
}
