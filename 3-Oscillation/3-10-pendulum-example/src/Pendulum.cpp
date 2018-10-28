#include "Pendulum.hpp"

Pendulum::Pendulum(glm::vec2 origin, double radius) {
  _origin = origin;
  _position = glm::vec2(0, 0);
  _radius = radius;
  _angle = PI / 4;
  _angularVelocity = 0.0;
  _angularAcceleration = 0.0;
  _damping = 0.995;
  _ballr = 48.0;
}

void Pendulum::go() {
  update();
  drag();
  display();
}

void Pendulum::update() {
  if (!_dragging) {
    float gravity = 0.98;
    _angularAcceleration = (-1 * gravity / _radius) * sin(_angle);
    _angularVelocity += _angularAcceleration;
    _angularVelocity *= _damping;
    _angle += _angularVelocity;
  }
}

void Pendulum::display() {
  _position = glm::vec2(_radius * sin(_angle),
                        _radius * cos(_angle));
  _position += _origin;
  ofSetLineWidth(2);
  ofSetColor(0);
  ofDrawLine(_origin.x, _origin.y, _position.x, _position.y);
  ofSetColor(100);
  if (_dragging) { ofSetColor(0); }
  ofDrawCircle(_position.x, _position.y, _ballr);
}

void Pendulum::clicked(int mx, int my) {
  double distance = glm::distance(glm::vec2(mx, my), _position);
  if (distance < _ballr) {
    _dragging = true;
  }
}

void Pendulum::stopDragging() {
  if (_dragging) {
    _angularVelocity = 0;
    _dragging = false;
  }
}

void Pendulum::drag() {
  if (_dragging) {
    glm::vec2 diff = _origin - glm::vec2(ofGetMouseX(), ofGetMouseY());
    _angle = atan2(-1 * diff.y, diff.x) - glm::radians(90.0);
  }
}
