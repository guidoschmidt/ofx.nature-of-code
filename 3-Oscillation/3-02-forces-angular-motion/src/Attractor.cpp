#include "Attractor.hpp"

Attractor::Attractor() {
  this->_mass = 10;
  this->_G = 0.1;
  this->_position = glm::vec2(ofGetWidth()  / 2,
                              ofGetHeight() / 2);
}

glm::vec2 Attractor::attract(Mover *mover) {
  glm::vec2 force = this->_position - mover->getPosition();
  double distance = glm::length(force);
  distance = glm::clamp(distance, 5.0, 25.0);
  force = glm::normalize(force);
  double strength = (this->_G * this->_mass * mover->getMass());
  strength /= (distance * distance);
  force *= strength;
  return force;
}

void Attractor::display() {
  ofSetColor(0);
  ofSetLineWidth(2);
  ofFill();
  ofDrawEllipse(this->_position.x, this->_position.y, 48, 48);
}
