#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  for (unsigned int i = 0; i < 20; i++) {
    this->_movers[i] = new Mover();
  }

}

//--------------------------------------------------------------
void ofApp::update(){
  for (Mover* mover : this->_movers) {
    mover->update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  for (Mover* mover : this->_movers) {
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
