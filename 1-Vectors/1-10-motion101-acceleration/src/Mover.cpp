#include "Mover.hpp"

Mover::Mover() {
  _position = glm::vec2( ofGetWidth() / 2, ofGetHeight() / 2);
  _velocity = glm::vec2(0, 0);
  _acceleration = glm::vec2(0, 0);
  _topSpeed = 2.0f;
}

void Mover::update() {
  ofVec2f mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  this->_acceleration = glm::normalize(glm::vec2(mouse - _position));
  this->_acceleration *= 0.2;
  this->_velocity += _acceleration;
  std::cout << this->_velocity << std::endl;
  this->_velocity.x = glm::clamp(this->_velocity.x,
                                 -this->_topSpeed,
                                  this->_topSpeed);
  this->_velocity.y = glm::clamp(this->_velocity.y,
                                 -this->_topSpeed,
                                  this->_topSpeed);
  this->_position += _velocity;
}

void Mover::display() {
  ofVec2f mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  ofFill();
  // Line
  ofSetColor(128, 128, 128);
  ofSetLineWidth(1.0f);
  ofDrawLine(this->_position, mouse);
  // Mouse
  ofSetColor(255, 0, 0);
  ofDrawEllipse(mouse, 20, 20);
  // Mover
  ofSetColor(255, 255, 255);
  ofDrawEllipse(_position, 100, 100);
}
