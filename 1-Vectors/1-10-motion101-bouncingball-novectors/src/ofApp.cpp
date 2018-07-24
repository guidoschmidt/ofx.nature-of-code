#include "ofApp.h"

float x = 100.0f;
float y = 100.0f;
float xSpeed = 2.5f;
float ySpeed = 2.0f;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
  x += xSpeed;
  y += ySpeed;
  if ((x > ofGetWidth()) || (x < 0)) {
    xSpeed *= -1;
  }
  if ((y > ofGetHeight()) || (y < 0)) {
    ySpeed *= -1;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  ofSetColor(250, 42, 128);
  ofDrawEllipse(x, y, 48, 48);
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
