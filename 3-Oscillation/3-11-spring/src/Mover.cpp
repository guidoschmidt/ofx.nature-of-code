#include "Mover.hpp"

Mover::Mover(float x, float y) {
  _position = glm::vec2(x, y);
  _velocity = glm::vec2(0, 0);
  _acceleration = glm::vec2(0, 0);
  _dragOffset = glm::vec2(0, 0);
  _dragging = false;
  _mass = 24;
  _damping = 0.98;
}

void Mover::update() {
  _velocity += _acceleration;
  _velocity *= _damping;
  _position += _velocity;
  _acceleration *= 0;
}

void Mover::applyForce(glm::vec2 force) {
  glm::vec2 f = force / _mass;
  _acceleration += f;
}

void Mover::display() {
  ofSetColor(128);
  if (_dragging) {
    ofSetColor(50);
  }
  ofFill();
  ofDrawEllipse(_position, _mass * 2, _mass * 2);
}

void Mover::clicked(int mx, int my) {
  float d = glm::distance(glm::vec2(mx, my), _position);
  if (d < _mass) {
    _dragging = true;
    _dragOffset.x = _position.x - mx;
    _dragOffset.y = _position.y - my;
  }
}

void Mover::stopDragging() {
  _dragging = false;
}

void Mover::drag(int mx, int my) {
  if (_dragging) {
    _position.x = mx + _dragOffset.x;
    _position.y = my + _dragOffset.y;
  }
}

void Mover::setPosition(glm::vec2 pos) {
  _position = pos;
}

void Mover::setVelocity(glm::vec2 vel) {
  _velocity = vel;
}

glm::vec2 Mover::getPosition() {
  return _position;
}

glm::vec2 Mover::getVelocity() {
  return _velocity;
}
