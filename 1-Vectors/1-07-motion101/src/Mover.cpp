#include "Mover.hpp"

Mover::Mover() {
  this->_position = glm::vec2(ofRandom(ofGetWidth(), ofGetHeight()));
  this->_velocity = glm::vec2(ofRandom(-10, 10), ofRandom(-10, 10));
}

void Mover::update() {
  this->_position += this->_velocity;
}

void Mover::display() {
  ofSetColor(241, 47, 128);
  ofDrawEllipse(this->_position,42, 42);
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
