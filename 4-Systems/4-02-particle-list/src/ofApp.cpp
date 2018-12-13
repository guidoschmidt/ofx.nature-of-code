#include "ofApp.h"

const int PARTICLE_COUNT = 300;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetBackgroundAuto(false);
  ofBackground(255);
  for (unsigned int i = 0; i < PARTICLE_COUNT; i++) {
    Particle* p = new Particle(glm::vec2(ofGetWidth() / 2,
                                         ofGetHeight() / 2));
    _particles.push_back(p);
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255, 255, 255, 5);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  for (auto p : _particles) {
    p->run();
  }
}
