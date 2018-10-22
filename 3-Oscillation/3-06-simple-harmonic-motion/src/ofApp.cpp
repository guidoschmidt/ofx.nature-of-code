#include "ofApp.h"

double angle = 0;
double angularVelocity = 0.03;
double amplitude = 300;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetSmoothLighting(true);
  ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  double x = amplitude * sin(angle);
  angle += angularVelocity;

  ofBackground(255);
  ofSetColor(0);
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  ofDrawLine(0, 0, x, 0);
  ofDrawCircle(x, 0, 20);
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
