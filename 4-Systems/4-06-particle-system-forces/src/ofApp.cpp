#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  _origin = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
  _particleSystem = new ParticleSystem(_origin);
}

//--------------------------------------------------------------
void ofApp::update() {
  glm::vec2 force = _origin - glm::vec2(ofGetMouseX(), ofGetMouseY());
  force = glm::normalize(force);
  force /= 1000.0;
  _gravity = force;
}

//--------------------------------------------------------------
void ofApp::draw(){
  _particleSystem->applyForce(_gravity);
  _particleSystem->addParticle();
  _particleSystem->run();
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
