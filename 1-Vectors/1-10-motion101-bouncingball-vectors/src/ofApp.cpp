#include "ofApp.h"

glm::vec2 position;
glm::vec2 velocity;

//--------------------------------------------------------------
void ofApp::setup(){
  position = glm::vec2(100, 100);
  velocity = glm::vec2(2.5f, 2.0f);
}

//--------------------------------------------------------------
void ofApp::update(){
  position += velocity;
  if ((position.x > ofGetWidth()) || (position.x < 0)) {
    velocity.x *= -1;
  }
  if ((position.y > ofGetHeight()) || (position.y < 0)) {
    velocity.y *= -1;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(42, 128, 250);
  ofDrawEllipse(position, 25, 25);
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
