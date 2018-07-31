#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  this->_mover = new Mover();
  this->_wind = glm::vec2(0.01, 0);
  this->_gravity = glm::vec2(0, 0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
  this->_mover->applyForce(this->_wind);
  this->_mover->applyForce(this->_gravity);
  this->_mover->update();
  this->_mover->checkEdges();
}

//--------------------------------------------------------------
void ofApp::draw(){
  this->_mover->display();
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
