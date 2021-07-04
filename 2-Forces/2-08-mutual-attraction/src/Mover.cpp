#include "Mover.hpp"

const double G = 0.72;

Mover::Mover(float mass, float x, float y) {
  this->_mass = mass;
  this->_position = glm::vec2(x, y);
  this->_velocity = glm::vec2(0, 0);
  this->_acceleration = glm::vec2(0, 0);
  int randomRed = ofRandom(130, 250);
  int randomGreen = ofRandom(130, 250);
  int randomBlue = ofRandom(130, 250);
  this->_color = glm::vec3(randomRed, randomGreen, randomBlue);
}

void Mover::applyForce(glm::vec2 force) {
  glm::vec2 f = force / this->_mass;
  this->_acceleration += f;
}

void Mover::update() {
  this->_velocity += this->_acceleration;
  this->_position += this->_velocity;
  this->_acceleration *= 0;
}

void Mover::display() {
  ofSetColor(this->_color.r, this->_color.g, this->_color.b);
  ofSetLineWidth(2.0);
  ofFill();
  ofDrawEllipse(this->_position.x,
                this->_position.y,
                this->_mass * 10,
                this->_mass * 10);
}

glm::vec2 Mover::attract(Mover* mover) {
  glm::vec2 force = mover->_position - this->_position;
  double d = glm::length(force);
  d = glm::clamp(d, 20.0, 70.0);
  force = glm::normalize(force);
  float strength = (G * this->_mass * mover->getMass()) / (d * d);
  force *= strength;
  return force;
}

float Mover::getMass() { return this->_mass; }

glm::vec2 Mover::getPosition() { return this->_position; }

ofColor Mover::getColor() {
  return ofColor(this->_color.r,
                 this->_color.g,
                 this->_color.b);
}
