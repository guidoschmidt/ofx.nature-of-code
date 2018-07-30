#include "Mover.hpp"

Mover::Mover() {
  this->_position = glm::vec2(ofGetWidth() / 2.0,
                              ofGetHeight() / 2.0);
  this->_velocity = glm::vec2(0, 0);
  this->_acceleration = glm::vec2(-0.001f, 0.01f);
  this->_topSpeed = 6.0f;
}

void Mover::update() {
  this->_acceleration = glm::vec2(ofRandom(0, 1), ofRandom(0, 1));
  this->_acceleration *= ofRandom(0, 2);
  this->_velocity += this->_acceleration;
  this->_velocity.x = glm::clamp(this->_velocity.x,
                                 -this->_topSpeed,
                                  this->_topSpeed);
  this->_velocity.y = glm::clamp(this->_velocity.y,
                                 -this->_topSpeed,
                                  this->_topSpeed);
  this->_position += this->_velocity;
}

void Mover::display() {
  ofSetColor(241, 47, 128);
  ofDrawEllipse(this->_position, 42, 42);
}

void Mover::checkEdges() {
  if (this->_position.x > ofGetWidth()) {
    this->_position.x = 0;
  }
  else if (this->_position.x < 0) {
    this->_position.x = ofGetWidth();
  }

  if (this->_position.y > ofGetHeight()) {
    this->_position.y = 0;
  } else if (this->_position.y < 0) {
    this->_position.y = ofGetHeight();
  }
}
