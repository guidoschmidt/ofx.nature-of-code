#include "ofApp.h"

ofColor backgroundColor; 
ofColor particleIntersectionColor;
ofColor particleColor;

//--------------------------------------------------------------
void ofApp::setup(){
  // Setup openframeworks
  ofSetFrameRate(120);

  // Setup colors
  backgroundColor.setHex(0xf2e3c9);
  particleColor.setHex(0x7ecfc0);
  particleIntersectionColor.setHex(0xef4b4b);

  // Setup particle system
  glm::vec2 origin = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
  _particleSystem = new ParticleSystem(origin);

  ofBackground(backgroundColor);
  _particleSystem->setParticleIntersectionColor(particleIntersectionColor);
  _particleSystem->setParticleColor(particleColor);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(backgroundColor);

  glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  for (int i = 0; i < 3; i++) {
    _particleSystem->addParticle(mouse);
  }
  _particleSystem->run();
  _particleSystem->calculateIntersections();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
