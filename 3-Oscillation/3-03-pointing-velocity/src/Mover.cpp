#include "Mover.hpp"

Mover::Mover() {
  _position = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
  _velocity = glm::vec2(0, 0);
  _acceleration = glm::vec2(0, 0);
  _topSpeed = 0.1f;
  _xOff = 1000;
  _yOff = 0;
  _r = 16;
}

void Mover::update() {
  glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  glm::vec2 direction = mouse - _position;
  direction = glm::normalize(direction);
  // direction *= 0.5f;
  _acceleration = direction;
  _velocity += _acceleration;
  this->_velocity.x = glm::clamp(this->_velocity.x, -_topSpeed, _topSpeed);
  this->_velocity.y = glm::clamp(this->_velocity.y, -_topSpeed, _topSpeed);
  _position += _velocity;
}

void Mover::display() {
  ofSetColor(0, 0, 0);
  ofPushMatrix();
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofTranslate(_position.x, _position.y);
  //ofRotateDeg(theta);
  ofDrawRectangle(0, 0, 30, 10);
  ofPopMatrix();

  glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  ofDrawEllipse(mouse.x, mouse.y, 10, 10);
}

void Mover::checkEdges() {
  if (_position.x > ofGetWidth()) {
    _position.x = 0;
  } else if (_position.x < 0) {
    _position.x = ofGetWidth();
  }

  if (_position.y > ofGetHeight()) {
    _position.y = 0;
  } else if (_position.y < 0) {
    _position.y = ofGetHeight();
  }
}
