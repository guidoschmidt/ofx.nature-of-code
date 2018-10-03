#include "Mover.hpp"

Mover::Mover(float mass, float x, float y) {
  this->_mass = mass;
  this->_position = glm::vec2(x, y);
  this->_velocity = glm::vec2(0, 0);
  this->_acceleration = glm::vec2(0, 0);
  this->_angle = 0;
  this->_angularVelocity = 0;
  this->_angularAcceleration = 0;
}

void Mover::applyForce(glm::vec2 force) {
  glm::vec2 f = force / this->_mass;
  this->_acceleration += f;
}

void Mover::update() {
  this->_velocity += this->_acceleration;
  this->_position += this->_velocity;

  this->_angularAcceleration = this->_acceleration.x / 3.0;
  this->_angularVelocity += this->_angularAcceleration;
  this->_angularVelocity = glm::clamp(this->_angularVelocity, -0.1, 0.1);
  this->_angle += this->_angularVelocity;

  this->_acceleration *= 0;
}

void Mover::display(double distance) {
  distance = ofMap(distance, 0, 200, 0, 1, true);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofPushMatrix();
  ofTranslate(this->_position.x, this->_position.y);
  ofRotateDeg(this->_angle);
  ofFill();
  ofSetColor(100, 200, 255 * distance);
  ofDrawRectangle(0, 0, this->_mass * 2, this->_mass * 30);
  ofPopMatrix();
}

glm::vec2 Mover::getPosition() {
  return this->_position;
}

double Mover::getMass() {
  return this->_mass;
}
