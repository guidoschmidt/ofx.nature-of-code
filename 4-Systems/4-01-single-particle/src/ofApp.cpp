#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  _particle = new Particle(glm::vec2(ofGetWidth() / 2,
                                     ofGetHeight() / 2));
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  _particle->run();
  if (_particle->isDead()) {
    _particle = new Particle(glm::vec2(ofGetWidth() / 2,
                                       ofGetHeight () / 2));
  }
}
