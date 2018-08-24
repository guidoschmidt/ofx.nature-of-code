#include "Attractor.hpp"

Attractor::Attractor() {
  this->_mass = 20;
  this->_position = glm::vec2(ofGetWidth()  / 2,
                              ofGetHeight() / 2);
  this->_G = 1;
  this->_dragOffset = glm::vec2(0, 0);
}

glm::vec2 Attractor::attract(Mover* mover) {
  glm::vec2 force = this->_position - mover->getPosition();
  double d = glm::length(force);
  d = glm::clamp(d, 5.0, 25.0);
  force = glm::normalize(force);
  float strength = (this->_G * this->_mass) / (d * d);
  force *= strength;
  return force;
}

void Attractor::display() {
  ofSetColor(0, 0, 0);
  if (this->_rollover) {
    ofSetColor(100, 100, 100);
  }
  ofDrawEllipse(this->_position.x, this->_position.y,
                this->_mass * 2, this->_mass * 2);
}

void Attractor::clicked(int mx, int my) {
  float dist = glm::distance(glm::vec2(mx, my), this->_position);
  if (dist < this->_mass) {
    this->_dragging = true;
    this->_dragOffset = glm::vec2(this->_position.x - mx,
                                  this->_position.y - my);
  }
}

void Attractor::hover(int mx, int my) {
  float dist = glm::distance(glm::vec2(mx, my), this->_position);
  if (dist < this->_mass) {
    this->_rollover = true;
  } else {
    this->_rollover = false;
  }
}

void Attractor::stopDragging() {
  this->_dragging = false;
}

void Attractor::drag() {
  if (this->_dragging) {
    this->_position = glm::vec2(ofGetMouseX() + this->_dragOffset.x,
                                ofGetMouseY() + this->_dragOffset.y);
  }
}
