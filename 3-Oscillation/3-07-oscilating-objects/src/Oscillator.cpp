#include "Oscillator.hpp"

Oscillator::Oscillator() {
  _angle = glm::vec2(0,0);
  _velocity = glm::vec2(ofRandom(-0.05, 0.05), ofRandom(-0.05, 0.05));
  _amplitude = glm::vec2(ofRandom(50, ofGetWidth()  / 2 - 50),
                         ofRandom(50, ofGetHeight() / 2 - 50));
  _color = glm::vec3(ofRandom(100, 255),
                     ofRandom(100, 255),
                     ofRandom(100, 255));
}

void Oscillator::oscillate() {
  _angle += _velocity;
}

void Oscillator::display() {
  float x = sin(_angle.x) * _amplitude.x;
  float y = sin(_angle.y) * _amplitude.y;

  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  ofSetLineWidth(2);
  ofSetColor(_color.r, _color.g, _color.b);
  ofFill();
  ofDrawLine(0, 0, x, y);
  ofDrawCircle(x, y, 20);
  ofPopMatrix();
}
