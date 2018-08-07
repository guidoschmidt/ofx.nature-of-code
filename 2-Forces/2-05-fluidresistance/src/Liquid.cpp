#include "Liquid.hpp"

Liquid::Liquid(float x, float y, float w, float h, float c) {
  this->_x = x;
  this->_y = y;
  this->_w = w;
  this->_h = h;
  this->_c = c;
}

const bool Liquid::contains(Mover *m) {
  glm::vec2 l = m->getPosition();
  return l.x > this->_x && l.x < this->_x + this->_w && l.y > this->_y &&
         l.y < this->_y + this->_h;
}

const glm::vec2 Liquid::drag(Mover *m) {
  float speed = glm::length(m->getVelocity());
  float dragMagnitude = this->_c * speed * speed;
  glm::vec2 dragForce = m->getVelocity();
  dragForce *= -1;
  dragForce = glm::normalize(dragForce);
  dragForce *= dragMagnitude;
  return dragForce;
}

const void Liquid::display() {
  ofSetLineWidth(0);
  ofSetColor(155, 255, 207);
  ofFill();
  ofDrawRectangle(this->_x, this->_y, this->_w, this->_h);
}
