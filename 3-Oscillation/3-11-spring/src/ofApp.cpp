#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  _mover = new Mover(ofGetWidth() / 2, 100);
  _spring = new Spring(ofGetWidth() / 2, 10, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  glm::vec2 gravity = glm::vec2(0, 0.01);
  _mover->applyForce(gravity);

  _spring->connect(_mover);
  _spring->constrainLength(_mover, 30, 200);
  _mover->update();
  _mover->drag(ofGetMouseX(), ofGetMouseY());

  _spring->displayLine(_mover);
  _mover->display();
  _spring->display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  _mover->clicked(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  _mover->stopDragging();
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
