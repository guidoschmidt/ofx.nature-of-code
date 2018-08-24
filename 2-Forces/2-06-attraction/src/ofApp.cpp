#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  this->_attractor = new Attractor();
  for (unsigned int i = 0; i < 100; i++) {
    this->_movers[i] = new Mover(ofRandom(5, 10),
                                 ofRandom(0, ofGetHeight()),
                                 ofRandom(0, ofGetHeight()));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  this->_attractor->hover(ofGetMouseX(), ofGetMouseY());
  this->_attractor->drag();
  for (auto mover : this->_movers) {
    glm::vec2 force = this->_attractor->attract(mover);
    mover->applyForce(force);
    mover->update();
    mover->checkEdges();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255, 255, 255);
  this->_attractor->display();
  for (auto mover : this->_movers) {
    mover->display();
  }
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
  this->_attractor->clicked(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  this->_attractor->stopDragging();
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
