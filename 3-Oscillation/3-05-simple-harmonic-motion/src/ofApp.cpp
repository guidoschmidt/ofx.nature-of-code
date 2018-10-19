#include "ofApp.h"

float period = 120;
float amplitude = 300;
float x = 0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
  x = amplitude * sin(TWO_PI * ofGetFrameNum() / period);
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  ofSetColor(0);
  ofSetLineWidth(2);
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  ofDrawLine(0, 0, x, 0);
  ofDrawEllipse(x, 0, 48, 48);
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
