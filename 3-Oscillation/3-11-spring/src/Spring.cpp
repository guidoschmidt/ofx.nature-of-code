#include "Spring.hpp"

Spring::Spring(float x, float y, int l) {
  _anchor = glm::vec2(x, y);
  _length = l;
}

void Spring::connect(Mover* b) {
  glm::vec2 force = b->getPosition() - _anchor;
  float d = glm::length(force);
  float stretch = d - _length;
  force = glm::normalize(force);
  force *= -1 * _k * stretch;
  b->applyForce(force);
}

void Spring::constrainLength(Mover* b, float minLength, float maxLength) {
  glm::vec2 dir = b->getPosition() - _anchor;
  float d = glm::length(dir);
  if (d < minLength) {
    dir = glm::normalize(dir);
    dir *= minLength;
    b->setPosition(_anchor + dir);
    b->setVelocity(glm::vec2(0, 0));
  }
  else if (d > maxLength) {
    dir = glm::normalize(dir);
    dir *= maxLength;
    b->setPosition(_anchor + dir);
    b->setVelocity(glm::vec2(0, 0));
  }
}

void Spring::display() {
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(_anchor.x, _anchor.y, 10, 10);
}

void Spring::displayLine(Mover *mover) {
  ofDrawLine(mover->getPosition(), _anchor);
}
