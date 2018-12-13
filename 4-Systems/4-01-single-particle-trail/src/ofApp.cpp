#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetBackgroundAuto(false);
  ofBackground(255);
  _particle = new Particle(glm::vec2(ofGetWidth() / 2,
                                     ofGetHeight() / 2));
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255, 255, 255, 5);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  _particle->run();
  if (_particle->isDead()) {
    _particle = new Particle(glm::vec2(ofGetWidth() / 2,
                                       ofGetHeight () / 2));
  }
}
