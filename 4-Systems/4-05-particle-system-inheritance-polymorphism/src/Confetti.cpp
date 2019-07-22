#include "Confetti.hpp"

Confetti::Confetti(glm::vec2 position) : Particle(position)
{
  _color = ofColor(0);
  _color.setHsb(ofRandom(0, 255), 255, 240);
}

void Confetti::display()
{
  ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
  ofSetColor(_color, _lifespan);
  ofFill();
  ofPushMatrix();
  ofTranslate(_position);
  float theta = ofMap(_lifespan * 100.0, 0, 200, 0, TWO_PI * 2);
  ofRotateDeg(theta);
  ofDrawRectangle(glm::vec2(0, 0), 12, 12);
  ofPopMatrix();
}
