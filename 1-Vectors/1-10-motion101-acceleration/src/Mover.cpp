#include "Mover.hpp"

Mover::Mover() {
  _position = glm::vec2( ofGetWidth() / 2, ofGetHeight() / 2);
  _velocity = glm::vec2(0, 0);
  _acceleration = glm::vec2(0, 0);
  _topSpeed = 2.0f;
}

void Mover::update() {
  //std::cout << ofGetMouseX() << ", " << ofGetMouseY() << std::endl;
  ofVec2f mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  this->_acceleration = glm::normalize(glm::vec2(_position - mouse));
  // this->_acceleration *= 0.2;
  // this->_velocity += _acceleration;
  // this->_velocity = glm::max(_velocity, _topSpeed);
  // this->_position += _velocity;
  // this->_position = mouse;
}

void Mover::display() {
  ofSetColor(255, 128, 42);
  ofFill();
  ofDrawEllipse(_position, 100, 100);
  ofSetLineWidth(5.0f);
  ofDrawLine(this->_position,
             this->_position - this->_acceleration);
}
