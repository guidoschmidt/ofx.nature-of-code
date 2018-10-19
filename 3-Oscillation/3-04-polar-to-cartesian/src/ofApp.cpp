#include "ofApp.h"

double theta = 0.0;
double r = 0;

//--------------------------------------------------------------
void ofApp::setup(){
  r = ofGetHeight() * 0.45;
  ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255, 255, 255);
  ofSetColor(42, 42, 42);
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  float x = r * cos(theta);
  float y= r * sin(theta);
  ofDrawLine(0, 0, x, y);
  ofDrawEllipse(x, y, 45, 45);
  theta += 0.02;
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
