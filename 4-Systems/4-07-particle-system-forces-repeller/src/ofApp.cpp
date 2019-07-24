#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  glm::vec2 systemOrigin = { ofGetWidth() / 2, ofGetHeight() / 2 };
  _particleSystem = new ParticleSystem(systemOrigin);
  glm::vec2 repellerOrigin = { ofGetWidth() / 2 - 20, ofGetHeight() / 2 };
  _repeller = new Repeller(repellerOrigin);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  _repeller->setPosition(glm::vec2(ofGetMouseX(), ofGetMouseY()));
  _particleSystem->addParticle();
  glm::vec2 gravity = glm::vec2(0, 0.0001);
  _particleSystem->applyForce(gravity);
  _particleSystem->applyRepeller(_repeller);
  _repeller->display();
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
