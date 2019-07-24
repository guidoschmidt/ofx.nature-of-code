#include "Repeller.hpp"

Repeller::Repeller(glm::vec2 origin) {
  _G = 10;
  _position = origin;
}

void Repeller::display() {
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawEllipse(_position, 48, 48);
}

glm::vec2 Repeller::repel(Particle* p) {
  glm::vec2 direction = _position - p->getPosition();
  float d = glm::length(direction);
  direction = glm::normalize(direction);
  d = glm::clamp(d, 50.0f, 100.0f);
  float force = -1 * _G / (d * d);
  direction *= force;
  return direction;
}
