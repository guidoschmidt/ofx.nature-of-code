#include "Ball.hpp"

Ball::Ball() {
  this->_position = glm::vec2(100, 100);
  this->_velocity = glm::vec2(2.5, 2.0);
}

void Ball::update() {
  this->_position += this->_velocity;
  if ((this->_position.x > ofGetWidth()) || (this->_position.x < 0)) {
    this->_velocity.x *= -1;
  }
  if ((this->_position.y > ofGetHeight()) || (this->_position.y < 0)) {
    this->_velocity.y *= -1;
  }
}

void Ball::display() {
  ofSetColor(128, 42, 250);
  ofDrawEllipse(this->_position, 50, 50);
}
